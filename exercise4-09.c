#include <stdio.h>
#include <stdlib.h>   /* for atof() */
#include <math.h>     /* for sin, exp, and pow */

#define MAXOP    100  /* max size of operand or operator */
#define NUMBER   '0'  /* signal that a number was found */
#define VARIABLE '1'  /* signal that a variable (a-z) was found */
#define LASTRES  26   /* variable index for the last printed result */

int getop(char []);
void push(double);
double pop(void);
void clear(void);

/* reverse Polish calculator */
int
main()
{
    int i, type, lastvar;
    double op1, op2, var['z' - 'a'], lastres = 0.0;
    char s[MAXOP];

    for (i = 0; i < ('z' - 'a'); i++)
        var[i] = 0.0;

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case VARIABLE:
            lastvar = s[0] - 'a';
            push(var[lastvar]);
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case '%':
            op2 = pop();
            op1 = pop();
            if (op2 != 0.0)
                if ((long) op2 == op2 && (long) op1 == op1)
                    push((long) op1 % (long) op2);
                else
                    printf("error: modulo requires integer operands\n");
            else
                printf("error: zero divisior for %%\n");
            break;
        case 'H':
            op2 = pop();
            printf("\t%.8g\n", op2);
            push(op2);
            break;
        case 'D':
            op2 = pop();
            push(op2);
            push(op2);
            break;
        case 'X':
            op2 = pop();
            op1 = pop();
            push(op1);
            push(op2);
            break;
        case 'C':
            clear();
            break;
        case 'S':
            push(sin(pop())); 
            break;
        case 'E':
            push(exp(pop()));
            break;
        case 'P':
            op2 = pop();
            push(pow(pop(), op2));
            break;
        case 'R':
            push(lastres);
            break;
        case '\n':
            op2 = pop();
            lastres = op2;
            printf("\t%.8g\n", op2);
            break;
        case '=':
            op2 = pop(); /* remove pushed value from variable */
            op2 = pop(); /* this is the correct value to store */
            var[lastvar] = op2;
            push(op2);   /* and push the store value again */
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}

#define MAXVAL  100   /* maximum depth of val stack */

int sp = 0;           /* next free stack position */
double val[MAXVAL];   /* value stack */

/* push:  push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop:  pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* clear: clear stack */
void clear(void)
{
    sp = 0;
}


#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop:  get next operator or numeric operand */
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-') {
        if (c >= 'a' && c <= 'z')
            return VARIABLE; /* variable */
        else
            return c;        /* not a number */
    }
    i = 0;
    if (c == '-') {
        c = getch(); /* look at the next char */
        if (!isdigit(c) && c != '.') {
            ungetch(c);
            return '-'; /* the operator - */
        }
        else {
            s[++i] = c;
        }
    }
    if (isdigit(c))   /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')     /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

int buf;            /* buffer for ungetch that also can hold an EOF */
int buf_full = 0;   /* flag if buffer is filled */

int getch(void)     /* get a (possibly pushed back) character */
{
    if (buf_full) {
        buf_full = 0;
        return buf;
    } else
        return getchar();
}

void ungetch(int c) /* push character back on input */
{
    if (buf_full)
        printf("ungetch: too many characters\n");
    else {
        buf = c;
        buf_full = 1;
    }
}
