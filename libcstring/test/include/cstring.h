#ifndef CSTRING_H
#define CSTRING_H

#define _Hardcoded_mode_   0x1
#define _Automatic_mode_   0x0 

#define _tear_down_      _Automatic_mode_
#if     _tear_down_  ==  _Hardcoded_mode_ 
    /* Deallocate the memory used by the library methods 
       by registering this function at function atexit();  
       OR call it at the end of main. */ 
    extern void tear_down(void);
#elif   _tear_down_  ==  _Automatic_mode_ 
    /* Automatically deallocate the memory used by the
       library methods at the end of program execution. */
    void tear_down(void) __attribute__((destructor));
#endif

#define _s_char_  0x0
#define _u_char_  0x1

#define ___stype__   _u_char_
#if ___stype__   ==  _s_char_
    typedef signed char char8_t;
#elif ___stype__ ==  _u_char_
    typedef unsigned char char8_t; 
#endif

typedef unsigned long long int uint64_t;

struct string
{    
    uint64_t i;
    uint64_t max;
    char8_t *buffer;
};

struct int128_t
{
    uint64_t index;
    uint64_t limit;
};

typedef struct string    string;
typedef struct int128_t  int128_t; 

#define null                0x0
#define new                 0x1 
#define string(...)        |0x1 ? Array8_t(__VA_ARGS__) : *((string *)0x0)
#define str()              |0x1 ? new_string()          : *((string *)0x0)

/* 
    Lightweight versions of some of the declared functions. 
*/

#define _push_back_all_(s, ch)                                     \
    s.buffer[s.i++] = ch

#define _push_back_(s, ch)                                         \
    s.i == s.max ? s.buffer = _dig_(&s) : 0,                       \
    s.buffer[s.i++] = ch

#define _pop_back_(s)                                              \
    s.i ? s.i-- : 0

#define _insert_char_(s, index, ch)                                \
    s.buffer[index] = ch

#define _char_(s, i)                                               \
    s.buffer[i]

#define _begin_(s)                                                 \
    s.buffer

#define _len_(s)                                                   \
    s.i

#define str_seek_set(s)                                            \
    _begin_(s) -= _len_(s)


#define _push_back_all__(s, ch)                                    \
    s->buffer[s->i++] = ch

#define _push_back__(s, ch)                                        \
    s->i == s->max ? s->buffer = _dig_(s) : 0,                     \
    s->buffer[s->i++] = ch

#define _pop_back__(s)                                             \
    s->i ? s->i-- : 0

#define _insert_char__(s, index, ch)                               \
    s->buffer[index] = ch

#define _char__(s, i)                                              \
    s->buffer[i]

#define _begin__(s)                                                \
    s->buffer

#define _len__(s)                                                  \
    s->i    

#define str_seeK_set(s)                                            \
    _begin__(s) -= _len__(s)


/* Initialize a string variable using individual characters. */
extern string Array8_t(uint64_t i, ...);


/* Assign a new string STR to a string variable. */
extern string assign(const char *str);


/* Initialize string variable. */
extern string $(const char *str);


/* Read string from stdin. */
extern string input_str(const char *msg);


/* Allocate Extra S bytes for str. 
   Also This function makes a set of configurations for function push_back_all() */
extern uint64_t range(string *str, uint64_t s);


/* Append ch to str. 
   This function rely on function range() */
extern void push_back_all(string *str, char8_t ch); 


/* Append ch to str. */
extern void push_back(string *str, char8_t ch); 


/* Delete the last character in str. */
extern void pop_back(string *str);


/* Append src to str. */
extern void append(string *str, const char *src); 


/* Append N characters of src to str. 
   This function rely on function range() */
extern void append_all(string *str, const char *src, uint64_t n);


/* Replace N characters in str With N characters of src, starting from index. */
extern void replace(string *str, uint64_t index,  const char *src, uint64_t n); 


/* Replace all the characters in str with N characters of src. */
extern void replace_all(string *str, const char *src, uint64_t n);


/* Insert SRC into str at position index. */
extern void insert(string *str, uint64_t index, const char *src);


/* Insert ch into str at position index. */
extern void insert_ch(string *str, uint64_t index, char ch); 


/* This function makes a set of configurations for function insert_char() */
extern int128_t irange(string *str, uint64_t index, uint64_t n);


/* Insert ch into str at position index. 
   This function rely on function irange() */
extern void insert_char(string *str, uint64_t index, char8_t ch);


/* Return concatenated strings of 2D Array. */
extern string concat2DArr(char **a, uint64_t s);


/* Remove N characters of str, starting from index. */
extern void slice(string *str, uint64_t index, uint64_t n);


/* Reverse the order of the characters in str. */
extern void reverse(string *str);


/* Compare s1 and s2. */ 
extern int str_cmp(string *s1, string *s2);


/* Compare N characters of s1 and s2. */
extern int str_ncmp(string *s1, string *s2, uint64_t n);


/* Swap content of s1 and s2. */
extern void swap(string *s1, string *s2);


/* Copy s2 into s1.  */
extern void copy(string *s1, string *s2);


/* Return the starting index of N characters in str which is matching the same 
   number of characters in SRC at REP a repetition of matching between both. */
extern uint64_t find(string *str, const char *src, uint64_t rep); 


/* Return the number of WORD repetition in str. */
extern uint64_t word_rep(string *str, const char *word); 


/* Display all the characters in str. */
extern void display(string *str);


/* Erase all the characters in str. */
extern void clear(string *str);


/* Erase all the characters in str and set the string's buffer to NULL. */
extern void erase(string *str);


/* De-allocate the memory associated with p and set p to NULL. */
extern void del(void *p, void **ptp);


/* Return the total number of characters that the string can hold before needing to allocate more memory. */
extern uint64_t capacity(string *str);


/* Return the total number of characters in str. */
extern uint64_t length(string *str);


/* Return constant pointer to null-terminated array which is holding content of str. */
extern const char *c_str(string *str);


/* Return constant pointer to null-terminated array which is holding content of str. */
extern const char8_t *cstr(string *str);


/* Return a write/read pointer to the first character in str. */ 
extern char8_t *begin(string *str);


/* Return constant pointer to the first character in str. */
extern const char8_t *cbegin(string *str);


/* Return 1 if str is Empty, 0 if not. */
extern int empty(string *str);


/* Shrink capacity of str to fit its content. */
extern void shrinkTofit(string *str);


/* Return reference to the last character in str. */
extern char8_t *back(string *str);


/* Return character from str by its index i. */
extern char8_t Char(string *str, uint64_t i); 


/* Attempt to allocate enough memory for specified number of characters N. */
extern void reserve(string *str, uint64_t n); 


/* Use this function to allocate enough memory for specified number of characters N.  
   Note: this function Act as malloc(); and realloc(); 
         the resulted string object is inappropriate for many of the library functions. */
extern void buffer(string *str, uint64_t n); 


/* Don't use this function. */
char8_t *_dig_(string *str); 


/* Create uninitialized string variables. */
extern void new_strings(string *str, uint64_t s);


/* Erase Array of strings. */
extern void erase_strings(string *str, uint64_t s);


/* Display Array of strings. */
extern void display_strings(string *str, uint64_t s);


/* Create uninitialized string variable. */
extern string new_string(void); 


/* A report shows the memory allocated by the library methods until invoking this function. */
extern void Used_memory(void);


/* Return malloc'd array holding the content of File fname. */
extern string FileToArray(const char *fname);


/* Write the content of ARR to a new File fname. */
extern void ArrayToFile(struct string *arr, const char *fname, const char *w_mode);


/* About author. */
extern void About_Author(void);


#endif
