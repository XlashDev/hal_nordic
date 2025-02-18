/*
 * Copyright (c) 2020 - 2024, Nordic Semiconductor ASA
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef NRFX_RESET_REASON_H
#define NRFX_RESET_REASON_H

#include <nrfx.h>
#include <hal/nrf_power.h>

#if !NRF_POWER_HAS_RESETREAS
#include <hal/nrf_reset.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup nrfx_reset_reason Generic Reset Reason layer
 * @{
 * @ingroup nrfx
 * @ingroup nrf_power
 * @ingroup nrf_reset
 *
 * @brief Helper layer that provides a uniform way of checking the reset reason.
 */

#if NRF_POWER_HAS_RESETREAS_CTRLAP || (defined(NRF_RESET) && NRF_RESET_HAS_CTRLAP_RESET) \
    || defined(__NRFX_DOXYGEN__)
/** @brief Symbol indicating whether CTRAP reset reason is present. */
#define NRFX_RESET_REASON_HAS_CTRLAP 1
#else
#define NRFX_RESET_REASON_HAS_CTRLAP 0
#endif

#if (defined(NRF_RESET) && NRF_RESET_HAS_NETWORK) || defined(__NRFX_DOXYGEN__)
/** @brief Symbol indicating whether network reset reasons are present. */
#define NRFX_RESET_REASON_HAS_NETWORK 1
#else
#define NRFX_RESET_REASON_HAS_NETWORK 0
#endif

#if NRF_POWER_HAS_RESETREAS_LPCOMP || defined(RESET_RESETREAS_LPCOMP_Msk) || \
    defined(__NRFX_DOXYGEN__)
/** @brief Symbol indicating whether LPCOMP reset reason is present. */
#define NRFX_RESET_REASON_HAS_LPCOMP 1
#else
#define NRFX_RESET_REASON_HAS_LPCOMP 0
#endif

#if NRF_POWER_HAS_RESETREAS_NFC || defined(RESET_RESETREAS_NFC_Msk) || defined(__NRFX_DOXYGEN__)
/** @brief Symbol indicating whether NFC reset reason is present. */
#define NRFX_RESET_REASON_HAS_NFC 1
#else
#define NRFX_RESET_REASON_HAS_NFC 0
#endif

#if NRF_POWER_HAS_RESETREAS_VBUS || (defined(NRF_RESET) && NRF_RESET_HAS_VBUS_RESET) \
    || defined(__NRFX_DOXYGEN__)
/** @brief Symbol indicating whether VBUS reset reason is present. */
#define NRFX_RESET_REASON_HAS_VBUS 1
#else
#define NRFX_RESET_REASON_HAS_VBUS 0
#endif

#if (defined(NRF_RESET) && NRF_RESET_HAS_CTRLAPSOFT_RESET) || defined(__NRFX_DOXYGEN__)
/** @brief Symbol indicating whether CTRL-AP reset reason is present. */
#define NRFX_RESET_REASON_HAS_CTRLAPSOFT 1
#else
#define NRFX_RESET_REASON_HAS_CTRLAPSOFT 0
#endif

#if (defined(NRF_RESET) && NRF_RESET_HAS_CTRLAPHARD_RESET) || defined(__NRFX_DOXYGEN__)
/** @brief Symbol indicating whether CTRL-AP hard reset reason is present. */
#define NRFX_RESET_REASON_HAS_CTRLAPHARD 1
#else
#define NRFX_RESET_REASON_HAS_CTRLAPHARD 0
#endif

#if (defined(NRF_RESET) && NRF_RESET_HAS_CTRLAPPIN_RESET) || defined(__NRFX_DOXYGEN__)
/** @brief Symbol indicating whether CTRL-AP pin reset reason is present. */
#define NRFX_RESET_REASON_HAS_CTRLAPPIN 1
#else
#define NRFX_RESET_REASON_HAS_CTRLAPPIN 0
#endif

#if (defined(NRF_RESET) && NRF_RESET_HAS_GRTC_RESET) || defined(__NRFX_DOXYGEN__)
/** @brief Symbol indicating whether GRTC reset reason is present. */
#define NRFX_RESET_REASON_HAS_GRTC 1
#else
#define NRFX_RESET_REASON_HAS_GRTC 0
#endif

#if (defined(NRF_RESET) && NRF_RESET_HAS_SECTAMPER_RESET) || defined(__NRFX_DOXYGEN__)
/** @brief Symbol indicating whether GRTC reset reason is present. */
#define NRFX_RESET_REASON_HAS_SECTAMPER 1
#else
#define NRFX_RESET_REASON_HAS_SECTAMPER 0
#endif

/** @brief Reset reason bit masks. */
typedef enum
{
#if !NRF_POWER_HAS_RESETREAS || defined(__NRFX_DOXYGEN__)
    /**< Reset from pin-reset detected. */
    NRFX_RESET_REASON_RESETPIN_MASK  = RESET_RESETREAS_RESETPIN_Msk,
    /**< Reset from watchdog/application watchdog timer 0 detected. */
    NRFX_RESET_REASON_DOG0_MASK      = RESET_RESETREAS_DOG0_Msk,
    /**< Reset from watchdog/application watchdog timer 0 detected. */
    NRFX_RESET_REASON_DOG_MASK       = NRFX_RESET_REASON_DOG0_MASK,
#if NRFX_RESET_REASON_HAS_CTRLAP
    /**< Reset from application CTRL-AP detected. */
    NRFX_RESET_REASON_CTRLAP_MASK    = RESET_RESETREAS_CTRLAP_Msk,
#endif
    /**< Reset from soft reset/application soft reset detected. Deprecated. */
    NRFX_RESETREAS_SREQ_MASK         = RESET_RESETREAS_SREQ_Msk,
    /**< Reset from soft reset/application soft reset detected. */
    NRFX_RESET_REASON_SREQ_MASK      = RESET_RESETREAS_SREQ_Msk,
    /**< Reset from CPU lockup/application CPU lockup detected. */
    NRFX_RESET_REASON_LOCKUP_MASK    = RESET_RESETREAS_LOCKUP_Msk,
    /**< Reset due to wakeup from System OFF mode when wakeup is triggered by DETECT signal from
     *   GPIO. */
    NRFX_RESET_REASON_OFF_MASK       = RESET_RESETREAS_OFF_Msk,
    /**< Reset due to wakeup from System OFF mode when wakeup is triggered by ANADETECT signal from
     *   LPCOMP. */
    NRFX_RESET_REASON_LPCOMP_MASK    = RESET_RESETREAS_LPCOMP_Msk,
    /**< Reset due to wakeup from System OFF mode when wakeup is triggered by entering the debug
     *   interface mode. */
    NRFX_RESET_REASON_DIF_MASK       = RESET_RESETREAS_DIF_Msk,
#if NRFX_RESET_REASON_HAS_NETWORK
    /**< Reset from network soft reset detected. */
    NRFX_RESET_REASON_LSREQ_MASK     = RESET_RESETREAS_LSREQ_Msk,
    /**< Reset from network CPU lockup detected. */
    NRFX_RESET_REASON_LLOCKUP_MASK   = RESET_RESETREAS_LLOCKUP_Msk,
    /**< Reset from network watchdog timer detected. */
    NRFX_RESET_REASON_LDOG_MASK      = RESET_RESETREAS_LDOG_Msk,
    /**< Force off reset from application core detected. */
    NRFX_RESET_REASON_MFORCEOFF_MASK = RESET_RESETREAS_MFORCEOFF_Msk,
#endif // NRFX_RESET_REASON_HAS_NETWORK
    /**< Reset after wakeup from System OFF mode due to NFC field being detected. */
    NRFX_RESET_REASON_NFC_MASK       = RESET_RESETREAS_NFC_Msk,
    /**< Reset from application watchdog timer 1 detected. */
    NRFX_RESET_REASON_DOG1_MASK      = RESET_RESETREAS_DOG1_Msk,
#if NRFX_RESET_REASON_HAS_VBUS
    /**< Reset after wakeup from System OFF mode due to VBUS rising into valid range. */
    NRFX_RESET_REASON_VBUS_MASK      = RESET_RESETREAS_VBUS_Msk,
#endif
#if NRFX_RESET_REASON_HAS_NETWORK
    /**< Reset from network CTRL-AP detected. */
    NRFX_RESET_REASON_LCTRLAP_MASK   = RESET_RESETREAS_LCTRLAP_Msk,
#endif // NRF_RESET_HAS_NETWORK
#if NRF_RESET_HAS_CTRLAPSOFT_RESET
    /**< Soft reset from CTRL-AP detected. */
    NRFX_RESET_REASON_CTRLAPSOFT_MASK = RESET_RESETREAS_CTRLAPSOFT_Msk,
#endif
#if NRFX_RESET_REASON_HAS_CTRLAPSOFT
    /**< Reset due to CTRL-AP hard reset. */
    NRFX_RESET_REASON_CTRLAPHARD_MASK = RESET_RESETREAS_CTRLAPHARD_Msk,
#endif
#if NRFX_RESET_REASON_HAS_CTRLAPPIN
    /**< Reset due to CTRL-AP pin reset. */
    NRFX_RESET_REASON_CTRLAPPIN_MASK  = RESET_RESETREAS_CTRLAPPIN_Msk,
#endif
#if NRFX_RESET_REASON_HAS_GRTC
    /**< Reset due to wakeup from GRTC. */
    NRFX_RESET_REASON_GRTC_MASK       = RESET_RESETREAS_GRTC_Msk,
#endif
#if NRFX_RESET_REASON_HAS_SECTAMPER
    /**< Reset due to illegal tampering of the device. */
    NRFX_RESET_REASON_SECTAMPER_MASK  = RESET_RESETREAS_SECTAMPER_Msk,
#endif
#else
    NRFX_RESET_REASON_RESETPIN_MASK   = POWER_RESETREAS_RESETPIN_Msk,
    NRFX_RESET_REASON_DOG_MASK        = POWER_RESETREAS_DOG_Msk,
    NRFX_RESET_REASON_SREQ_MASK       = POWER_RESETREAS_SREQ_Msk ,
    NRFX_RESET_REASON_LOCKUP_MASK     = POWER_RESETREAS_LOCKUP_Msk,
    NRFX_RESET_REASON_OFF_MASK        = POWER_RESETREAS_OFF_Msk,
#if NRFX_RESET_REASON_HAS_CTRLAP
    NRFX_RESET_REASON_CTRLAP_MASK     = POWER_RESETREAS_CTRLAP_Msk,
#endif
#if NRFX_RESET_REASON_HAS_LPCOMP
    NRFX_RESET_REASON_LPCOMP_MASK     = POWER_RESETREAS_LPCOMP_Msk,
#endif
    NRFX_RESET_REASON_DIF_MASK        = POWER_RESETREAS_DIF_Msk,
#if NRFX_RESET_REASON_HAS_NFC
    NRFX_RESET_REASON_NFC_MASK        = POWER_RESETREAS_NFC_Msk,
#endif
#if NRFX_RESET_REASON_HAS_VBUS
    NRFX_RESET_REASON_VBUS_MASK       = POWER_RESETREAS_VBUS_Msk,
#endif
#endif // !NRF_POWER_HAS_RESETREAS || defined(__NRFX_DOXYGEN__)
} nrfx_reset_reason_mask_t;

/**
 * @brief Function for getting the reset reason bitmask.
 *
 * Unless cleared, the RESETREAS register is cumulative.
 * If none of the reset sources is flagged, the chip was reset from the on-chip reset generator.
 * This indicates a power-on-reset or a brown out reset.
 *
 * @return Mask of reset reasons constructed from @ref nrfx_reset_reason_mask_t values.
 */
__STATIC_INLINE uint32_t nrfx_reset_reason_get(void)
{
#if NRF_POWER_HAS_RESETREAS
    return nrf_power_resetreas_get(NRF_POWER);
#else
    return nrf_reset_resetreas_get(NRF_RESET);
#endif
}

/**
 * @brief Function for clearing the selected reset reason fields.
 *
 * @param[in] mask Mask constructed from @ref nrfx_reset_reason_mask_t values.
 */
__STATIC_INLINE void nrfx_reset_reason_clear(uint32_t mask)
{
#if NRF_POWER_HAS_RESETREAS
    nrf_power_resetreas_clear(NRF_POWER, mask);
#else
    nrf_reset_resetreas_clear(NRF_RESET, mask);
#endif
}

/** @} */

#ifdef __cplusplus
}
#endif

#endif // NRFX_RESET_REASON_H
