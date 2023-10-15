#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

const int MAX_CHARS = 100;
int validate_input(const char *input);
void find_address(char *input);
void input_upper(char *input);
void remove_EOL(char *source);

int main(int argc, char *argv[])
{
    char *input = argv[1];

    if (argc < 2)
    {
        return 1;
    }

    int errcode = validate_input(input);
    if (errcode != 0)
    {
        return errcode;
    }
    input_upper(input);
    find_address(input);

    return 0;
}

int validate_input(const char *input)
{

    for (int i = 0; input[i] != '\0'; i++)
    {
        char ch = input[i];
        if (((ch < 'A') || (ch > 'Z' && ch < 'a') || (ch > 'z')) && ch != ' ')
        {
            fprintf(stderr, "Error: input must contain only letter or space");
            return 1;
        }
    }
    return 0;
}

void input_upper(char *input)
{

    for (int i = 0; input[i]; i++)
    {
        input[i] = toupper(input[i]);
    }
}

void find_address(char *input)
{
    char address[MAX_CHARS];
    char next_characters[MAX_CHARS];
    char address_match[MAX_CHARS];
    next_characters[0] = '\0';

    int input_len = strlen(input);

    while (fgets(address, sizeof(address), (stdin)) != NULL)
    {

        for (int i = 0; address[i]; i++)
        {
            address[i] = toupper(address[i]);
        }

        remove_EOL(address);

        char *result = strstr(address, input);
        if (result != NULL && *result == *address)
        {
            if (strlen(input) == strlen(address))
            {
                printf("Found: %s\n", address);
                break;
            }
            else
            {
                strcpy(address_match, address);
                char next_char[2] = "";
                next_char[0] = address[input_len];
                if (strstr(next_characters, next_char) == NULL)
                {
                    strcat(next_characters, next_char);
                }
            }
        }
    }

    int next_characters_len = strlen(next_characters);
    if (next_characters_len == 0)
    {
        printf("Not found");
    }
    else if (next_characters_len == 1)
    {
        printf("Found: %s", address_match);
    }
    else
    {
        printf("Enable: %s", next_characters);
    }
}

/**
 * Removes EOL characters from source
 * @param source string to replace EOL in
 */
void remove_EOL(char *source)
{
    char *enter;

    if ((enter = strchr(source, '\n')) != NULL)
    {
        *enter = '\0';
    }

    if ((enter = strchr(source, '\r')) != NULL)
    {
        *enter = '\0';
    }
}
