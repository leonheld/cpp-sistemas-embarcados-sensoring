/*
 * file: Temperatura.h
 *
 * Descricao: Classe Temperatura utilizada para realizar a leitura do sensor de
 * temperatura, e data data/hora da leitura realizada.
 *
 * Autor: Eduardo Augusto Bezerra
 * Data: 09/12/2021
 *
 * Ultima Alteracao: Eduardo Augusto Bezerra
 * Data da ultima alteracao: 09/12/2021
 *
 */

#pragma once

//#include "ClockCalendar.h"
#include "Sensor.h"

class Temperatura : public Sensor {
  // ClockCalendar dataHora;

 protected:
  void readSensor();
};