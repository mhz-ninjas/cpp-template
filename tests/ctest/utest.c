#include "mu_test.h"

#define _GNU_SOURCE  /* to define Math constants */
#include <math.h>

#include "geometry.h"
#include "funcs.h"

BEGIN_TEST(test_with_no_assert_will_fail)

	TRACE_LOG("this will fail, at least one ASSERT_XXX is required\n");
	/*
	ASSERT_THAT(42);
	*/
END_TEST

BEGIN_TEST(test_integer_comparaisons)
	int a = 100;
	int b = 200;
	int mx = MAX(a, b);
	int mn = MIN(a, b);
	ASSERT_THAT(mx > mn);

	ASSERT_THAT( MAX(a,b) > MIN(a,b) );

	TRACE_LOG("%d", MAX(3, 12));

END_TEST

BEGIN_TEST(add_small_ints)
	int a = 42;
	int b = 100;
	int r = add(a, b);

	ASSERT_THAT( r == 142);
	ASSERT_EQUAL_INT(142, r);
END_TEST

volatile int HUGE_INT_VALUE = (int)(~0U>>1);
BEGIN_TEST(add_large_numbers_will_fail)
	int large = HUGE_INT_VALUE;
	int larger;
	int delta;

	TRACE_LOG("(int)(~0U>>1)     ==  %d ", large);
	ASSERT_THAT(large > 0);

	larger = add(large, 1);
	TRACE_LOG("(int)(~0U>>1) + 1 == %d ", larger);

	ASSERT_NOT_EQUAL_INT(larger, large);
	delta = larger - large;
	TRACE_LOG("delta == %d", delta);
	ASSERT_EQUAL_INT(delta, 1);
	ASSERT_EQUAL_INT(larger - 1, large);
	ASSERT_THAT( larger == large -1);
END_TEST


BEGIN_TEST(accessing_null_pointer_will_fail)
	int *p = 0;
	ASSERT_THAT(p == 0);
	ASSERT_EQUAL_PTR(p, NULL);

	/* DANGER */
	*p = 42;

	/* Will not reach next statement */
	ASSERT_THAT(1!=0);
END_TEST

BEGIN_TEST(say_hello)
	const char* msg = say();

	ASSERT_NOT_EQUAL_PTR(msg, NULL);
	ASSERT_EQUAL_STR(msg, "Join Linux Haters club!");
END_TEST


BEGIN_TEST(work_in_progress)
	ASSERT_THAT(say() != 0);
END_TEST

BEGIN_TEST(test_c_strings)
	const char* snull = 0;
	const char* msg = "hello";

	ASSERT_EQUAL_STR(msg, "hello");
	ASSERT_NOT_EQUAL_STR(snull, "");
	ASSERT_EQUAL_STR(snull, "");

END_TEST

BEGIN_TEST(test_assert_thats)
	int n = 42;

	ASSERT_THAT(n > 0);
	ASSERT_THAT(n == 42);
	ASSERT_THAT(n != 10);
	ASSERT_THAT(n < 10);

END_TEST

BEGIN_TEST(compute_pi_approximation)
	double computed_pi = compute_pi(TAYLOR_TERMS);

	TRACE_LOG("Computed Pi = %.9f", computed_pi);
	ASSERT_THAT(fabs(computed_pi - M_PI) < 0.00001);
END_TEST

TEST_SUITE(MUnit Test Demo!)
	TEST(test_with_no_assert_will_fail)
	TEST(test_integer_comparaisons)
	TEST(add_small_ints)
	TEST(add_large_numbers_will_fail)

	TEST(accessing_null_pointer_will_fail)
	IGNORE_TEST(work_in_progress)
	TEST(say_hello)

	TEST(test_c_strings)
	TEST(test_assert_thats)

	TEST(compute_pi_approximation)
END_SUITE
