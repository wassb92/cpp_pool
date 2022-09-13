/*
** EPITECH PROJECT, 2022
** day14a ex00
** File description:
** main
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../Algorithm.hpp"
#include "../Array.hpp"
#include "../Stack.hpp"
#include "../Command.hpp"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(test_Algorithm, simple_string, .init = redirect_all_std)
{
    int a = 42;
    int b = 21;
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
    std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
    std::cout << "clamp(0, a, b) = " << ::clamp(0, a, b) << std::endl;
    std::string c = "ghi";
    std::string d = "abc";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
    std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
    std::cout << "clamp(\"def\", c, d) = " << ::clamp(std::string("def"), c, d) << std::endl;

    cr_assert_stdout_eq_str("a = 21, b = 42\nmin(a, b) = 21\nmax(a, b) = 42\nclamp(0, a, b) = 21\nc = abc, d = ghi\nmin(c, d) = abc\nmax(c, d) = ghi\nclamp(\"def\", c, d) = def\n");
}

Test(test_Array, simple_string, .init = redirect_all_std)
{
    Array<int, 3> array;

    try {
        array[0] = 21;
        array[1] = 42;
        array[2] = 84;
        array[3] = 84;
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "size = " << array.size() << std::endl;
    std::cout << array << std::endl;
    array
        .convert<float>([](const int &v) { return static_cast<float>(v) / 10.f; })
        .forEach([](const float &v) { std::cout << v << std::endl; });

    cr_assert_stdout_eq_str("Out of range\nsize = 3\n[21, 42, 84]\n2.1\n4.2\n8.4\n");
}

Test(test_Stack, simple_string, .init = redirect_all_std)
{
    Stack stack;
    stack.push(42.21);
    stack.push(84.42);
    stack.push(21.12);
    stack.add();
    stack.div();
    try {
        stack.mul();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << stack.top() << std::endl;
    cr_assert_stdout_eq_str("Not enough operands\n2.50036\n");
}

Test(test_Command, simple_string, .init = redirect_all_std)
{
    Command command;
    Stack stack;
    try {
        command.registerCommand("push", [&stack]() { stack.push(4.2); });
        command.registerCommand("display", [&stack]() { std::cout << stack.top() << std::endl; });
        command.registerCommand("add", [&stack]() { stack.add(); });
        command.registerCommand("sub", [&stack]() { stack.sub(); });
        command.registerCommand("mul", [&stack]() { stack.mul(); });
        command.registerCommand("div", [&stack]() { stack.div(); });
        command.registerCommand("display", []() {});
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        command.executeCommand("push");
        command.executeCommand("push");
        command.executeCommand("push");
        command.executeCommand("add");
        command.executeCommand("div");
        command.executeCommand("display");
        command.executeCommand("nau");
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    cr_assert_stdout_eq_str("Already registered command\n2\nUnknow command\n");
}
