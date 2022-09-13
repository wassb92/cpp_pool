/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** unit test lib
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include "../list.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

static void int_displayer(const void *data)
{
    int value = *((int *)data);
    printf("%d\n", value);
}

static void test_size(list_t list_head)
{
    printf("There are %u elements in the list\n", list_get_size(list_head));
    list_dump(list_head, &int_displayer);
}

static void test_del(list_t *list_head)
{
    list_del_elem_at_back(list_head);
    printf("There are %u elements in the list\n", list_get_size(*list_head));
    list_dump(*list_head, &int_displayer);
}

Test(test_size1, simple_string, .init = redirect_all_std)
{
    list_t list_head = NULL;
    int i = 5;
    int j = 42;
    int k = 3;

    list_add_elem_at_back(&list_head, &i);
    list_add_elem_at_back(&list_head, &j);
    list_add_elem_at_back(&list_head, &k);
    test_size(list_head);
    fflush(NULL);
    list_clear(&list_head);

    cr_assert_stdout_eq_str("There are 3 elements in the list\n5\n42\n3\n\
        There are 2 elements in the list\n5\n42\n6");
}

Test(test_add, simple_string, .init = redirect_all_std)
{
    list_t list_head = NULL;
    int i = 5;
    int j = 42;
    int k = 3;
    int a = 34444;
    int b = 32323235;

    list_add_elem_at_back(&list_head, &i);
    list_add_elem_at_back(&list_head, &j);
    list_add_elem_at_back(&list_head, &k);
    list_add_elem_at_front(&list_head, &a);
    list_add_elem_at_position(&list_head, &b, 4);
    printf("%d\n", list_get_size(list_head));
    fflush(NULL);
    list_clear(&list_head);

    cr_assert_stdout_eq_str("5\n");
}