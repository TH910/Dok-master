#include "messpunkt.h"

messpunkt::messpunkt() {}

messpunkt::messpunkt(double tx, double ty, double tz) : sx(tx), sy(ty), sz(tz) {}

messpunkt::messpunkt(char *stream)
{

  char extract_stream[250];
  char start[] = "6dmt2";
  char end[] = "6dmtr";

  char *ptrStart = strstr(stream, start);
  char *ptrEnd = strstr(stream, end);
  *ptrEnd = '\0';
  strcpy(extract_stream, ptrStart);
  // printf("%s",extract_stream);
  char *pch;
  pch = strtok(extract_stream, " []");
  int num = 0;
  int printon = 0;
  double buf = 0;
  while (pch != NULL)
  {

    switch (num)
    {
    case 7:
      buf = atof(pch);
      if (printon == 1)
        printf("Float value of sx %f\n", buf);
      sx = buf;
      break;
    case 8:
      buf = atof(pch);
      if (printon == 1)
        printf("Float value of sy %f\n", buf);
      sy = buf;
      break;
    case 9:
      buf = atof(pch);
      if (printon == 1)
        printf("Float value of sz %f\n", buf);
      sz = buf;
      break;
    default:
      break;
    }
    // printf("%s in Aufruf %d\n",pch,num);
    pch = strtok(NULL, " []");
    num++;
  }
}

messpunkt::~messpunkt() {}
void messpunkt::anzeigen()
{
  std::cout << sx << " : " << sy << " : " << sz << std::endl;
}
