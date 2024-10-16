/*** includes ***/

/*
  The <termios.h> header contains the definitions used by the terminal
  I/O interfaces (see the XBD specification, General Terminal Interface
  for the structures and names defined)
*/
#include <termios.h>

/*
  The <unistd.h> header defines miscellaneous symbolic
  constants and types, and declares miscellaneous functions.
  The contents of this header are shown below.
*/
#include <unistd.h>

void enableRawMode() {
  struct termios raw;
}

/**
  Runs a text editor in the terminal.
  By default, the terminal starts in "canonical mode" or "cooked mode".
  Keyboard input is only sent to your program when the user presses Enter.

  This is useful for many programs: it lets the user type in a line
  of text, use Backspace to fix errors until they get their input
  exactly the way they want it, and finally press Enter to send
  it to the program.

  This does not work well for programs with more complex user interfaces,
  like TEXT EDITORS. We want to process each keypress as it comes in, so
  we can respond to it immediately.

  We want to use raw mode. We need to turn off many flags in the terminal
  to activate this mode.
 */
int main() {
  char c;

  /*
  ssize_t read(int fildes, void *buf, size_t nbyte)

  The read() function attempts to read nbyte bytes from
  the file associated with the open file descriptor, fildes,
  into the buffer pointed to by buf.

  STDIN_FILENO - file number of stdin. It is 0.
  ssize_t
    return type of read(). It is a signed integral type.
    Used for a count of bytes or an error indication.

  We are asking read() to read 1 byte (character) from
  the standard input into the variable c (&c) and to keep
  doing it until there are no more bytes to read.

  Press 'q' to quit.
  */
  while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q');
  return 0;
}
