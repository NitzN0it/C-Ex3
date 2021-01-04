#include <stdio.h>
#include <stdlib.h>

#define WORD 30
#define LINE 256
#define MAXCHAR 256*250
void print_line(char* str,int char_count);
int is_part_of_word(char ch);
int k = 1;
int similar_b(char* s, char* t, int n, int s_size)
{
	//s is the word from the text
	//t is the word we are searching for
	int s_counter = 0, t_counter = 0;
	while(is_part_of_word(*(s+s_counter)) == 1)
	{
		if ( (*(s+s_counter) == '\t') || (*(s+s_counter) == '\n') || (*(s+s_counter) == '\0') || (*(t+t_counter) == '\0') )
			break;
		if ((*(s+s_counter) != *(t+t_counter)))
		{
			n--;
			s_counter++;
		}
		else
		{
			s_counter++;
			t_counter++;
		}
	}

	if((n>=0))
	{
		if ((*(t+t_counter+1) == '\0') && (*(s+s_counter+n+1) == '\0'))
			return 1;
	}
	return 0;
}
int similar_a(char* s, char* t, int n)
{
	if((*s=='\0'))
	{
		return 0;
	}
	int s_counter = 0, t_counter = 0;
	while(is_part_of_word(*(s+s_counter)) == 1)
	{	
		if ((n<0) || (*(s+s_counter) == '\n') || (*(s+s_counter) == '\0') || (*(t+t_counter) == '\0') )
			break;
		if ((*(s+s_counter) != *(t+t_counter)))
		{
			n--;
			s_counter++;
		}
		else
		{
			s_counter++;
			t_counter++;
		}
	}
	if(n>=0)
		return 1;
	return 0;
}
void print_where_the_word_is(char* str,char* word ,int len)
{
	int char_count = 0,temp_word_count = 0;
		char* temp_word = NULL;
		while ((char_count < len))
		{
			while (is_part_of_word(*(str+char_count)) == 0)
			{
				char_count++;
			}
			temp_word = (char* ) malloc(WORD*sizeof(char));
			if (temp_word == NULL)
			{
				printf("problem");
				return;
			}
			temp_word_count = 0;
			while ((is_part_of_word(*(str+char_count)) == 1) && (char_count<len))
			{
				*(temp_word+temp_word_count) = *(str+char_count);
				char_count++;
				temp_word_count++;
			}
			int sim = similar_a(temp_word,word,0);
			if (sim == 1)
			{
				print_line(str,char_count-1);
			}
			free(temp_word);	
		}
}
void print_line(char* str,int char_count)
{
	while((*(str+char_count) != '\n'))
	{
		char_count--;
	}
	char_count++;
	while(*(str+char_count) != '\n')
	{
		printf("%c",str[char_count]);
		char_count++;
	}
	printf("\n");
}
int is_part_of_word(char ch)
{
	if((ch != ' ') && (ch != '\n') && (ch != '\t') && (ch != '\0'))
		return 1;
	return 0;
}
void get_search_word(char* str,char* word)
{
	int i=0;
	while((*(str+i) >= 'a') && (*(str+i) <= 'z'))
	{
		*(word+i) = *(str+i);
		i++;
	}
	*(word+i+1)='\0';
}
int get_to_start_of_text(char* str)
{
	int i = 0,row_num=1;;
		while(row_num!=3)
		{
			i++;
			if (*(str+i) == '\n')
			{
				i++;
				row_num++;
			}
		}
	str+=i;
	return i;
}
int get_operation_type(char* str)
{
	int char_count=0;
	while (*(str+char_count) != ' ')
		char_count++;
	char_count++;
	if (*(str+char_count) == 'a')
		return 1;
	if (*(str+char_count) == 'b')
		return 2;
	return 0;
}
void print_all_similar(char* str,char* word ,int len)
{
		int char_count = 0,temp_word_count = 0;
		char* temp_word = NULL;
		while ((char_count < len))
		{
			while (is_part_of_word(*(str+char_count)) == 0)
			{
				char_count++;
			}
			temp_word = (char* ) malloc(WORD*sizeof(char));
			if (temp_word == NULL)
			{
				printf("problem");
				return;
			}
			temp_word_count = 0;
			while ((is_part_of_word(*(str+char_count)) == 1) && (char_count<len))
			{
				*(temp_word+temp_word_count) = *(str+char_count);
				char_count++;
				temp_word_count++;
			}
			int sim = similar_b(temp_word,word,1,temp_word_count);
			if (sim == 1)
			{
				for(int i=0;i<=temp_word_count;i++)
				{
					printf("%c",*(temp_word+i));
				}
				printf("\n");
			}
			free(temp_word);	
		}
}
int main(int argc, char* argv[])
{
	FILE *fp;
	char str[MAXCHAR];
	char *str_p=str;
	fp = stdin;
	if (fp == NULL)
	{
		printf("Error opening file");
		return 1;
	}
	int i = 0;
	while ((*(str+i)=fgetc(fp)) != EOF)
	{
		i++;
	}
	fclose(fp);
	char word[30];
	get_search_word(str,word);
	int opr_type= get_operation_type(str);
	str_p+=get_to_start_of_text(str_p);
	if (opr_type == 1)
		print_where_the_word_is(str_p,word,i);
	if (opr_type == 2)
		print_all_similar(str_p,word,i);
	return 0;
}