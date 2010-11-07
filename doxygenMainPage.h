/** \mainpage
 *
 * Tidbits is a C++ code snippet/utility library composed by Naja Melan. It consists of a number of git repositories which can be included by opensource projects individually
 * or as a collection by using the tidbits repository. Many of the code snippets are copied from or inspired by other authors. Reference to source shall given
 * whenever possible. No copyright claims are made for this code. All rights remain with the original authors, unless for code written by Naja Melan
 * which is in the public domain.
 *
 * At the moment the library is very young and no claims for quality can yet be made. I have thusfar not released any opensource projects that make use of this
 * library and the library must thus be considered as under construction. If you have good code snippets like this and want to join this project, I am happy
 * to collaborate. It will be all the better if different people take on the maintainance of different snippets. The modular design of the library makes this
 * very easy. Especially if you see your own code in TidBits and would like to maintain it, drop me a line and I make you the maintainer of the repository.
 *
 * najamelan <-> gmail
 *
 * Everything in tidbits always assumes that the main working directory of TidBits_Cpp is in your include path
 *
 *
 * <hr />
 *
 * <b>Coding conventions in tidbits</b>
 *
 *
 * Exceptions are when an original author of a tidbit chooses to maintain the repository for that tidbit, then they decide on style as well as anything else.
 *
 * -# includes local to global in order to verify that headers are independant of other includes
 * -# vertical alignment whereever possible
 * -# tabwith 3 to allow vertical alignment to be practical
 * -# everything in tidbits namespace
 * -# return types go on a separate line than function names
 * -# between braces and contets put a space
 * -# consider this: http://www.joelonsoftware.com/articles/Wrong.html
 * -# no indentation inside namespace, but indentation in about anything else. Consider identation syntax!
 * -# prefer concise code. I prefer the empty page. Opposed to Joel Spolsky I do omit braces around a single conditional line of code
 *    I think rigorous identation and spacing permits it
 * -# whenever in even the slightest doubt about something you write, add a TODO comment in order for it to get looked at later
 * -# compile with treat warnings as errors at high warning level (eg /W4 on msvc)
 * -# write portable code (eg disable language extensions) and don't use platform specific calls if cross platform is possible
 * -# prefer references above pointers
 *
 *
 * <b>Naming conventions in tidbits</b>
 * these are quite more important to keep consistant.
 * -# header files are lowercase, words separated by underscores
 * -# macros       are uppercase, words separated by underscores
 * -# type names                are lowercase with exception of the first letter of each word
 * -# variable and method names are lowercase with exception of the first letter of each word except the first, so: myLocalVariable
 *
 * <b>Character Encoding conventions in tidbits</b>
 *  -# understand the basics by reading: http://www.joelonsoftware.com/articles/Unicode.html
 *  -# generally stick to utf-8, but I still need to come up with more detailed instructions
 */
