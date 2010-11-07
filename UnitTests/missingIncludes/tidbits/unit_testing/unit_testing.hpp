THIS FILE SHOULD NOT COMPILE

This module is required to do unit testing.

The idea is that the library allows for unit testing all the submodules present on your system. 
Because C++ does not deal with missing include files, you should include this directory LAST! 
That means that your compiler will only include the empty include files from here if they can't
be found elsewhere. However you need submodule unit_testing to run the testSuite, so this one does not compile.
If you have the submodule, then this file might end up being included because the order of include
directories is wrong!