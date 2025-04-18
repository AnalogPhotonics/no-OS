/***************************************************************************//**
 *   @file   common_data.c
 *   @brief  Defines common data to be used by adf5611 examples.
 *   @author Josemene (jude.osemene@analog.com)
********************************************************************************
 * Copyright 2024(c) Analog Devices, Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of Analog Devices, Inc. nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY ANALOG DEVICES, INC. “AS IS” AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 * EVENT SHALL ANALOG DEVICES, INC. BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*******************************************************************************/

#include "common_data.h"

struct no_os_uart_init_param adf5611_uart_ip = {
	.device_id = UART_DEVICE_ID,
	.irq_id = UART_IRQ_ID,
	.asynchronous_rx = true,
	.baud_rate = UART_BAUDRATE,
	.size = NO_OS_UART_CS_8,
	.parity = NO_OS_UART_PAR_NO,
	.stop = NO_OS_UART_STOP_1_BIT,
	.extra = UART_EXTRA,
	.platform_ops = UART_OPS,
};

struct no_os_spi_init_param adf5611_spi_ip = {
	.device_id = SPI_DEVICE_ID,
	.max_speed_hz = 1500000,
	.bit_order = NO_OS_SPI_BIT_ORDER_MSB_FIRST,
	.mode = NO_OS_SPI_MODE_0,
	.platform_ops = SPI_OPS,
	.chip_select = SPI_CS,
	.extra = SPI_EXTRA,
};

struct no_os_i2c_init_param adf5611_i2c_ip = {
	.device_id = I2C_DEVICE_ID,
	.platform_ops = I2C_OPS,
	.max_speed_hz = 100000,
	.extra = I2C_EXTRA,
	.slave_address = 0x54
};

struct eeprom_24xx32a_init_param adf5611_eeprom_init_param = {
	.i2c_init = &adf5611_i2c_ip,
};

struct no_os_eeprom_init_param adf5611_eeprom_ip = {
	.device_id = 5,
	.platform_ops = &eeprom_24xx32a_ops,
	.extra = &adf5611_eeprom_init_param,
};

struct adf5611_init_param adf5611_ip = {
	.spi_init = &adf5611_spi_ip,
	.spi4wire = true,
	.cmos_3v3 = false,
	.ref_clk_freq = 122880000,
	.rfout_freq = 12000000000,
	.ref_div = 2,
	.cp_i = 15,
	.bleed_word = 17,
	.ld_count = 12,
	.id = ID_ADF5611,
};
