/***************************************************************************//**
 *   @file   parameters.h
 *   @brief  Definitions specific to Mbed platform used by ad74416h
 *           project.
 *   @author Antoniu Miclaus (antoniu.miclaus@analog.com)
********************************************************************************
 * Copyright 2023(c) Analog Devices, Inc.
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
#ifndef __PARAMETERS_H__
#define __PARAMETERS_H__

#include <PinNames.h>
#include "mbed_uart.h"
#include "mbed_i2c.h"
#include "mbed_spi.h"
#include "no_os_uart.h"
#include "no_os_gpio.h"
#include "mbed_gpio.h"
#include "no_os_irq.h"
#include "mbed_irq.h"
#include "mbed_gpio_irq.h"

#define UART_TX_PIN	    CONSOLE_TX
#define	UART_RX_PIN	    CONSOLE_RX
#define UART_DEVICE_ID  0
#define UART_IRQ_ID     0
#define UART_BAUDRATE   115200
#define UART_EXTRA	&ad74416h_uart_extra_ip
#define UART_OPS        &mbed_uart_ops

/* I2C Pin mapping for Arduino interface */
#define I2C_SCL         ARDUINO_UNO_D15
#define I2C_SDA         ARDUINO_UNO_D14
#define I2C_DEVICE_ID   0
#define I2C_OPS         &mbed_i2c_ops

#define SPI_BAUDRATE    1000000
#define SPI_OPS         &mbed_spi_ops
#define SPI_EXTRA       &ad74416h_spi_extra
#define SPI_DEVICE_ID   0
#define SPI_CS          ARDUINO_UNO_D10

#define GPIO_OPS	&mbed_gpio_ops
#define GPIO_ADC_RDY	ARDUINO_UNO_D2
#define GPIO_EXTRA 	&ad74416h_gpio_extra

#define GPIO_IRQ_ADC_ID		0
#define GPIO_IRQ_OPS		&mbed_gpio_irq_ops
#define GPIO_IRQ_ADC_EXTRA	&mbed_adc_rdy_gpio_irq_extra

extern struct mbed_uart_init_param ad74416h_uart_extra_ip;
extern struct mbed_i2c_init_param ad74416h_i2c_extra;
extern struct mbed_spi_init_param ad74416h_spi_extra;
extern struct no_os_gpio_init_param adc_rdy_gpio_ip;
extern struct no_os_irq_init_param adc_rdy_gpio_irq_ip;
extern struct mbed_gpio_init_param ad74416h_gpio_extra;
extern struct mbed_gpio_irq_init_param mbed_adc_rdy_gpio_irq_extra;

#endif /* __PARAMETERS_H__ */
