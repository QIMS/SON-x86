/*
* kernel.c
* kernel of operation system SON
* "the System for One Night"
* v0.1
* by Renat Mansurov
*/

void kernelmain(void)
{
  const char *str = "SON: 'the System for One Night'"; // Экран приветствия
  char *vidptr = (char*)0xb8000; // Указатель на адрес начала видеопамяти
  unsigned int j = 0;
  unsigned int i = 0;

/*
* Clear screen loop
* 25 lines
* 80 columns
* 2 bytes ASCII elements
* (8 symbol + 8 attribute)
*/

while(j < 80 * 25 * 2)
  {
    vidptr[j] = ' '; // Пустой символ
    vidptr[j+1] = 0x02; // 0x02 - Green
    j = j + 2;
  }

j = 0;

/*
* Write string loop
*/

while(str[j] != '\0')
  {
    vidptr[i] = str[j];
    vidptr[i+1] = 0x02;
    ++j;
    i = i + 2;
  }

return;

}
