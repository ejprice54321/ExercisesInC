/* Simple example using Glib.

From http://www.ibm.com/developerworks/linux/tutorials/l-glib/

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <glib.h>

int main(){

  gchar* contents;
  gsize length = NULL;
  gint* val;

  int i;

  /*reads the file and puts it into the contents array*/
  gboolean file_read = g_file_get_contents("foo.txt", &contents, &length, NULL);

  if (!file_read){
    // checks if the file was read
    return 1;
  }

  /*these are the params for the string split*/
  gint max_tokens = 100000;
  const gchar* delimiter = " ";

  /*splits the string and puts it into an array of gchars*/
  gchar** text_array = g_strsplit(contents, delimiter, max_tokens);

  /*makes the hash table with the params of a hash function and equality function*/
  GHashTable* hash = g_hash_table_new(g_str_hash, g_str_equal);

  /*iterates through the text_array, checks if the table contains the word:
      if it does, adds the word to the table with a value of 1
      if it doesn't, adds one to the word value*/
  for (i = 0; text_array[i] != NULL; i++){
    if (!g_hash_table_contains(hash, text_array[i])){
      g_hash_table_insert(hash, text_array[i], (gpointer) 1);
    } else {
      val = g_hash_table_lookup(hash, text_array[i]) + 1;
      // this is just for error check, Sophie's knows why it's still here
      // g_printf("%d\n", g_hash_table_lookup(hash, text_array[i]));
      g_hash_table_insert(hash, text_array[i], val);
    }
  }

  g_hash_table_destroy(hash);
  return 0;
}
