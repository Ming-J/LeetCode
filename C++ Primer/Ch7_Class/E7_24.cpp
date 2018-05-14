/*
Give your screen class three constructor: a default constructor; a
constructor that takes values for height and width and initializes the
contents to hold the given number of blanks; and a constructor that
takes values height, and a character to use as the contents of the
screen.
*/

class Screen{
public:
  Screen() = default;
  Screen(int h, int w): height(h), width(h), content(h*d,' '){}
  screen(int h, int w, char c) : height(h), width(h), content(h*d,c){}
private:
  int height = 0;
  int width = 0;
  std::string content;
};
