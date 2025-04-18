/***************************************************************************//**
 *   @file   ltc4332.h
 *   @brief  Header file of SPI ltc4332 Interface
 *   @author Paul Benoit (paul.benoit@analog.com)
********************************************************************************
 * Copyright 2022(c) Analog Devices, Inc.
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

#ifndef SRC_LTC4332_SPI_H_
#define SRC_LTC4332_SPI_H_

#include "no_os_spi.h"

/**
 * @struct no_os_spi_desc
 * @brief Structure initialization with the platform specific SPI functions
 */
extern const struct no_os_spi_platform_ops ltc4332_spi_platform_ops;

/* Initialize the SPI communication peripheral. */
int32_t ltc4332_spi_init(struct no_os_spi_desc **desc,
			 const struct no_os_spi_init_param *param);

/* Free the resources allocated by no_os_spi_init(). */
int32_t ltc4332_spi_remove(struct no_os_spi_desc *desc);

/* Write and read data to/from SPI. */
int32_t ltc4332_spi_write_and_read(struct no_os_spi_desc *desc, uint8_t *data,
				   uint16_t bytes_number);

#endif /* SRC_LTC4332_SPI_H_ */
