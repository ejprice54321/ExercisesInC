#include <stdio.h>
#include <unistd.h>
#include <getopt.h>

int main(int argc, char **argv)
{
  char line[80]; // characters that will be scanned from stdin
  char ch; // the character that will be set to the tag if there is one
  char opt = 'w'; // the option that we have, default is write'
  int count;

  while((ch = getopt(argc, argv, "a:")) != EOF) {
  // check for a tag in the command line
    switch(ch){
      // checks through those lines, only option is 'a' otherwise it throws
      // an error
      case 'a':
        opt = ch;
        optind--;
        break;
      default:
        fprintf(stderr, "Unkown option: %s\n", optarg);
        return 1;
    }

  }
  //skip past the option that we just read
  argc -= optind;
  argv += optind;

  // create pointers for all of the arguments we pass in
  FILE *files[argc];

  while (scanf("%79[^\n]\n", line) == 1){
    /* while there is actually something to scan from stdin:
    - print to stdout
    - check through each file entered, open it for appending or
      writing depending on the option tag, print to the files that
      were passed in
    */
    printf("%s\n", line);

    for (count = 0; count < argc; count++){
      if (opt == 'a'){
        files[count] = fopen(argv[count], "a");
      } else {
        files[count] = fopen(argv[count], "w");
      }
      fprintf(files[count], "%s\n", line);
      fclose(files[count]);
    }
  }
  // for (count = 0; count < argc; count++){
  //   // close all of the files
  //   fclose(files[count]);
  // }
  return 0;
}
