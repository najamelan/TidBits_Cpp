
/** make sure the tests compile and run (exclude compile time tests that fail)
 *  uncomment the next line to check the compile time tests
 *
 *	 Current tibits that use this define are:
 *  -# CTAssert
 */

#define ONLY_RUNTIME_TESTS

// Tidbits to be tested

#include <tidbits/ctassert/test_ctassert.hpp>
#include <tidbits/unit_testing/test_unit_testing.hpp>

// Unit testing includes

#include <tidbits/unit_testing/unit_testing.hpp>


// System includes

#include <iostream>





using namespace tidbits;


/// Keeps track of the test results. Only used in this compilation unit.
struct TestResult
{
	public:
		std::string message					;
		int 			tests_count 			;
		int 			tests_passed_count 	;
		int 			tests_failed_count 	;

		TestResult() :
				tests_count			( 0 )
			,	tests_passed_count( 0 )
			,	tests_failed_count( 0 )
		{}
};


/// This will run the tests and save the results, it deletes the pointer
void
runTest( UnitTesting* test, TestResult& testResult  )
{
		test->run_test_case();

		testResult.message 					+= test->get_message					()	;
		testResult.tests_count 				+= test->get_tests_count			()	;
		testResult.tests_passed_count 	+= test->get_tests_passed_count	()	;
		testResult.tests_failed_count 	+= test->get_tests_failed_count	()	;

		delete test;
}


/// run all tests of Tidbits and present the results to std::cout

/**
 * Currently this application relies on your compiler searching for includes in a certain order.
 * Stub includes are used to allow compilation and testing when only a subset of the existing
 * modules are present on your system.
 *
 * There is a directory TidBits_Cpp/UnitTests/missingIncludes which provides stubs for all test includes for
 * this application. This way if you include this directory last in your project all includes are found
 * even if the modules don't exist on your system. Using defines that are only set in the "real" headers
 * we can then omit testing modules that aren't there.
 *
 * The msvc2010 project included already has all project settings set properly for this to work. Currently
 * no makefile is available yet. If you want to contribute to porting this to linux by creating a makefile
 * that achieves the goal, please do so and send me a pull request of the git repo
 *
 *
 * TODO test if this approach is portable, if not look for alternatives
 * The main goals of this are that the user can download any number of available submodules using git
 * and consequently compile the testSuitApp without having to make any changes to the code and
 * run it to run unit tests on all the present modules while ignoring the absent ones
 *
 */

int
main()
{
   std::cout << "TidBits Library. Test Suite Application.\n" << std::endl;

	TestResult testResult;

	runTest( new TestUnitTesting, testResult );

   // Test CTAssert
	#ifdef test_ctassert_hpp

		runTest( new TestCTAssert(), testResult );

	#endif


   // Test suite
   std::cout 														<< testResult.message 					<< std::endl	;
   std::cout << "\n\nTidbits test suite results:\n" 													<< std::endl	;
   std::cout << "   Tests run   : " 						<< testResult.tests_count 				<< std::endl	;
   std::cout << "   Tests passed: " 						<< testResult.tests_passed_count		<< std::endl	;
   std::cout << "   Tests failed: " 						<< testResult.tests_failed_count		<< std::endl	;


	if		 ( testResult.tests_count 			== 0 )

		std::cout << "\nSomething went wrong, nothing got tested. Check whether"
						 "you have any modules on your harddisk and if the includes"
						 "can be found."																			<< std::endl	;


	else if( testResult.tests_failed_count == 0 )

	   std::cout << "\nTest OK" 																				<< std::endl	;


   else

	   std::cout << "\nTest NOT OK. " << testResult.tests_failed_count << " tests failed" 	<< std::endl	;



   std::cin.get();
   return 0;
}

