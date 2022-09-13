/*
** EPITECH PROJECT, 2022
** day 05
** File description:
** string
*/

#ifndef STRING_H_
#define STRING_H_

typedef struct string_s string_t;

struct string_s {
    char *str;
    void (*assign_s)(string_t *, const string_t *);
    void (*assign_c)(string_t *, const char *);
    void (*append_s)(string_t *, const string_t *);
    void (*append_c)(string_t *, const char *);
    char (*at)(const string_t *, size_t);
    void (*clear)(string_t *);
    int (*length)(const string_t *);
    int (*compare_s)(const string_t *, const string_t *);
    int (*compare_c)(const string_t *, const char *);
    size_t (*copy)(const string_t *, char *, size_t, size_t);
    const char *(*c_str)(const string_t *);
    int (*empty)(const string_t *);
    int (*find_s)(const string_t *, const string_t *, size_t);
    int (*find_c)(const string_t *, const char *, size_t);
    void (*insert_c)(string_t *, size_t, const char *);
    void (*insert_s)(string_t *, size_t, const string_t *);
    int (*to_int)(const string_t *);
    string_t **(*split_s)(const string_t *, char);
    char **(*split_c)(const string_t *, char);
    void (*print)(const string_t *this);
    void (*join_c)(string_t *this, char delim, const char *const *array);
    void (*join_s)(string_t *this, char delim, const string_t *const *array);
};

/* ex00 */

void string_init(string_t *this, const char *s);
void string_destroy(string_t *this);

/* ex01 */

void assign_s(string_t *this, const string_t *str);
void assign_c(string_t *this, const char *s);

/* ex02 */

void append_s(string_t *this, const string_t *ap);
void append_c(string_t *this, const char *ap);

/* ex03 */

char at(const string_t *this, size_t pos);
void clear(string_t *this);
int length(const string_t *this);
int compare_s(const string_t *this, const string_t *str);
int compare_c(const string_t *this, const char *str);
size_t copy(const string_t *this, char *s, size_t n, size_t pos);
const char *c_str(const string_t *this);
int empty(const string_t *this);
int find_s(const string_t *this, const string_t *str, size_t pos);
int find_c(const string_t *this, const char *str, size_t pos);
void insert_c(string_t *this, size_t pos, const char *str);
void insert_s(string_t *this, size_t pos, const string_t *str);
int to_int(const string_t *this);
string_t **split_s(const string_t *this, char separator);
char **split_c(const string_t *this, char separator);
void print(const string_t *this);
void join_c(string_t *this, char delim, const char *const *array);
void join_s(string_t *this, char delim, const string_t *const *array);

#endif /* !STRING_H_ */