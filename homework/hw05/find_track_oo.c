/* Example code for Exercises in C.

Modified version of an example from Chapter 2.5 of Head First C.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define NUM_TRACKS 5

char tracks[][80] = {
    "So What",
    "Freddie Freeloader",
    "Blue in Green",
    "All Blues",
    "Flamenco Sketches"
};


typedef struct {
    regex_t regex_struct;
    int status_flag;
} Regex;


/* Returns a new Regex that matches the given pattern.
 *
 * pattern: string regex
 * flags: flags passed to regcomp
 * returns: new Regex
 */
Regex* make_regex(char* pattern, int flags) {

  Regex* regex =  malloc(sizeof(Regex));

  regex_t regex_add;
  int status = 1;

  regex->regex_struct = regex_add;
  regex->status_flag = status;

  int ret = regcomp(&(regex->regex_struct), pattern, flags);

  printf("%s\n", pattern);

  if (ret) {
      fprintf(stderr, "Could not compile regex\n");
      exit(1);
  }
  printf("made regex\n");
  return regex;
}

/* Checks whether a regex matches a string.
 *
 * regex: Regex
 * s: string
 * returns: 1 if there's a match, 0 otherwise
 */
int regex_match(Regex* regex, char *s) {

  char msgbuf[100];
  //
  // regex_t regex_add;
  //
  // regex->regex_struct = regex_add;

  int ret = regexec(&(regex->regex_struct), s, 0, NULL, 0);

  printf("%i\n", ret);

  if (!ret){
    printf("Found match!");
    return 1;
  }else {
    regerror(ret, &(regex->regex_struct), msgbuf, sizeof(msgbuf));
    fprintf(stderr, "Regex match failed: %s\n", msgbuf);
    return 0;
  }
}

/* Frees a Regex.
 *
 * regex: Regex
 */
void regex_free(Regex* regex) {
  regfree(&(regex->regex_struct));
}


/* Finds all tracks that match the given pattern.
 *
 * Prints track number and title.
 */
void find_track_regex(char pattern[])
{
    int i;

    Regex* regex = make_regex(pattern, REG_EXTENDED | REG_NOSUB);

    // printf("%i\n", regex->status_flag);

    for (i=0; i<NUM_TRACKS; i++) {
    	if (regex_match(regex, tracks[i])) {
    	    printf("Track %i: '%s'\n", i, tracks[i]);
    	}
    }

    regex_free(regex);
}


int main (int argc, char* argv[])
{
    char* pattern = "F.*F.*";
    find_track_regex(pattern);

    return 0;
}
