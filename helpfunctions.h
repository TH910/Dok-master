#ifndef HELPFUNCTIONS_H
#define HELPFUNCTIONS_H

#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <vector>
#include "messpunkt.h"


/**
 * @brief Liest eine csv-Datei zeilenweise ein und erzeugt daraus messpunkt Objekte und legt diese in einem std::vector Objekt ab
 * 
 * @param path Dateipfad zur csv-Datei 
 * @return std::vector<messpunkt> container mit messpunkt objecten, die aus der csv-Datei erstellt wurden
 */
std::vector<messpunkt>csv_einlesen(const char* path);
/**
 * @brief schreibt einzelne messpunkt Objekte z
 * 
 * @param csv_data enthält den zu schreibenen std::vector Container mit den Objekten messpunkt 
 */
void csv_schreiben(std::vector<messpunkt> csv_data);



void conv_vec_to_arr(std::vector<messpunkt> data,double array[3][3]);



#endif // HELPFUNCTIONS_H

