/*
 * Copyright 2016-2018 <Admobilize>
 * MATRIX Labs  [http://creator.matrix.one]
 * This file is part of MATRIX Creator HAL
 *
 * MATRIX Creator HAL is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "./bus_android.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include "./creator_memory_map.h"

#include <android/log.h>
#include <android/looper.h>

const char* TAG = "bus_android";
#define LOGV(...) __android_log_print(ANDROID_LOG_VERBOSE, TAG, __VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN, TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, TAG, __VA_ARGS__)
#define ASSERT(cond, ...) if (!(cond)) { __android_log_assert(#cond, TAG, __VA_ARGS__);}


namespace matrix_hal {

struct hardware_address {
  uint8_t readnwrite : 1;
  uint16_t reg : 15;
};

BusAndroid::BusAndroid()
    : spi_fd_(0),
      spi_mode_(3),
      spi_bits_(8),
      spi_speed_(15000000),
      spi_delay_(0) {}

BusAndroid::~BusAndroid() {
  if (spi_fd_) Close();
}
bool BusAndroid::Init(std::string device_name) {

  client_ = APeripheralManagerClient_new();
  ASSERT(client_, "failed to open peripheral manager client");
  int num_spi_buses;
  char ** listSpiBuses = APeripheralManagerClient_listSpiBuses(client_, &num_spi_buses);
  ASSERT(num_spi_buses == 0, "failed to get SPI list buses");

  return true;
}

bool BusAndroid::SpiTransfer(unsigned char *send_buffer,
                            unsigned char *receive_buffer, unsigned int size) {
  
  return true;
}

bool BusAndroid::Read(uint16_t add, unsigned char *data, int length) {

  hardware_address *hw_addr = reinterpret_cast<hardware_address *>(tx_buffer_);
  
  return false;
}

bool BusAndroid::Write(uint16_t add, unsigned char *data, int length) {

  hardware_address *hw_addr = reinterpret_cast<hardware_address *>(tx_buffer_);
  
  return false;
}

void BusAndroid::Close(void) { 
  APeripheralManagerClient_delete(client_);
  close(spi_fd_); 
}

};  // namespace matrix_hal
