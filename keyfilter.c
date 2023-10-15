#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

const int MAX_CHARS = 100;
int validate_input(const char *input);
void find_address(char *input);
void str_to_uppercase(char *input);
void remove_EOL(char *source);

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Error: input must be provided");
        return 1;
    }

    char *input = argv[1];

    int errcode = validate_input(input);
    if (errcode != 0)
    {
        return errcode;
    }
    str_to_uppercase(input);
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

void str_to_uppercase(char *input)
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

    size_t input_len = strlen(input);

    while (fgets(address, sizeof(address), (stdin)) != NULL)
    {
        str_to_uppercase(address);

        remove_EOL(address);

        char *result = strstr(address, input);
        if (result != NULL && *result == *address)
        {
            strcpy(address_match, address);
            char next_char[2] = "";
            next_char[0] = address[input_len];
            if (strstr(next_characters, next_char) == NULL)
            {
                strcat(next_characters, next_char);
            }

            // exact match found
            if (input_len > 0 && input_len == strlen(address))
            {
                strcat(next_characters, " ");
                break;
            }
        }
    }

    size_t next_characters_len = strlen(next_characters);
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
