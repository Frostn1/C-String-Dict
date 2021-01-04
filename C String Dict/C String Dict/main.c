#include <stdio.h>
#include <stdbool.h>
#define MAXLENGTH 32
bool is_suffix_in_dict(char* str, char* dict[], int n);
int main()
{
	char* str = "easist";
	char* str1 = "prevented";
	char* str2 = "faMo,Us";
	char* noun_suffixes[] = { "msi","re","sci","ssen","tnem","tsi" };
	char* verb_suffixes[] = { "de","eta","ezi","gni","yfi" };
	char* adj_suffixes[] = { "elba","evi","hsi","la","luf","suo" };

	if (is_suffix_in_dict(str2, adj_suffixes, 6) == true)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}


}

bool is_suffix_in_dict(char* str, char* dict[], int n)
{
	int strCount = 0, dictCount = 0;
	bool flag = true;
	for (int i = 0; i < n; i++)
	{
		dictCount = strlen(dict[i])-1;
		flag = true;
		for (int j = strlen(str) / 2; j < strlen(str); j++)
		{
			if (tolower(dict[i][dictCount]) == tolower(str[j]))
			{
				dictCount--;
				flag = true;
			}
			else if(isalpha(str[j]))
			{
				flag = false;
				dictCount = strlen(dict[i])-1;
			}
		}
		if (flag == true && dict[i][dictCount] == str[strlen(str) - 1] || dictCount == -1)
		{
			return true;
		}
	}
	return false;
}
