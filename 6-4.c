#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
struct tnode *addword(struct tnode *p, char *w);
void treeprint(struct tnode *);
int getword(char *,int);

void treeprint(struct tnode *p);

struct tnode {
	char *word;
	int count;
	struct tnode *list;
};

int main(void)
{
	struct tnode *root;
	char word[MAXWORD];
	char *number;

	root = NULL;

	while (getword(word,MAXWORD) != EOF)
	{
		if (isalpha(word[0]))
		{
			root = addword(root, word);
		}
	}

	treeprint(root);
	return 0;
}

struct tnode *talloc(void);
char *strdup01(char *s);

struct tnode *addword(struct tnode *p, char *w)
{
	int cond;

	if (p == NULL)
	{
		p = talloc();
		p->word = strdup01(w);
		p -> count = 1;
	}
	else if ((cond = strcmp(w, p->word)) == 0)
	{
		p ->count++;
		return p;
	}
	else 
	{
		p->list = addword(p->list,w);
	}
	return p;
}

void treeprint(struct tnode *p)
{
	if (p != NULL) 
	{
		treeprint(p->list);
		printf("%4d %s\n",p->count, p->word);
	}
}

struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}

char *strdup01(char *s)
{
	char *p;

	p = (char *) malloc(strlen(s) + 1);
	if (p != NULL)
	{
		strcpy(p,s);
	}
	return p;
}

int getword(char *word, int lim)
{
	int c,getch(void);
	void ungetch(int);
	char *w = word;

	while (isspace(c = getch()));
	if (c != EOF)
	{
		*w++ = c;
	}
	if (!isalpha(c)) 
	{
		*w = '\0';
		return c;
	}
	for (; --lim > 0; w++)
	{
		if (!isalnum(*w = getch()))
		{
			ungetch(*w);
			break;
		}
	}
	*w = '\0';
	return word[0];
}

int cmp(const void *x, const void *y)
{
	//return ((
}


#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
	{
		printf("ungetch: too many characters\n");
	}
	else
	{
		buf[bufp++] = c;
	}
}