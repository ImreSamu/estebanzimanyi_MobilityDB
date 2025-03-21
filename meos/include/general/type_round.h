/*****************************************************************************
 *
 * This MobilityDB code is provided under The PostgreSQL License.
 * Copyright (c) 2016-2024, Université libre de Bruxelles and MobilityDB
 * contributors
 *
 * MobilityDB includes portions of PostGIS version 3 source code released
 * under the GNU General Public License (GPLv2 or later).
 * Copyright (c) 2001-2024, PostGIS contributors
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation for any purpose, without fee, and without a written
 * agreement is hereby granted, provided that the above copyright notice and
 * this paragraph and the following two paragraphs appear in all copies.
 *
 * IN NO EVENT SHALL UNIVERSITE LIBRE DE BRUXELLES BE LIABLE TO ANY PARTY FOR
 * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES, INCLUDING
 * LOST PROFITS, ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION,
 * EVEN IF UNIVERSITE LIBRE DE BRUXELLES HAS BEEN ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 *
 * UNIVERSITE LIBRE DE BRUXELLES SPECIFICALLY DISCLAIMS ANY WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE. THE SOFTWARE PROVIDED HEREUNDER IS ON
 * AN "AS IS" BASIS, AND UNIVERSITE LIBRE DE BRUXELLES HAS NO OBLIGATIONS TO
 * PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.
 *
 *****************************************************************************/

/**
 * @brief Basic functions for rounding the float components of types
 */

#ifndef __TYPE_ROUND_H__
#define __TYPE_ROUND_H__

/* PostgreSQL */
#include <postgres.h>
/* MEOS */
#include <meos.h>
#if NPOINT
  #include "npoint/tnpoint.h"
#endif
#if CBUFFER
  #include "cbuffer/tcbuffer.h"
#endif

/*****************************************************************************/

extern double float_round(double d, int maxdd);
extern Datum datum_round_float(Datum value, Datum size);
extern Datum datum_round_geo(Datum value, Datum size);
#if CBUFFER
extern Datum datum_cbuffer_round(Datum buffer, Datum size);
extern Cbuffer *cbuffer_round(const Cbuffer *buffer, int maxdd);
extern Set *cbufferset_round(const Set *s, int maxdd);
extern Temporal *tcbuffer_round(const Temporal *temp, int maxdd);
#endif /* CBUFFER */
#if NPOINT
extern Datum datum_npoint_round(Datum npoint, Datum size);
extern Npoint *npoint_round(const Npoint *np, int maxdd);
extern Nsegment *nsegment_round(const Nsegment *ns, int maxdd);
extern Set *npointset_round(const Set *s, int maxdd);
extern Temporal *tnpoint_round(const Temporal *temp, Datum size);
#endif /* NPOINT */

/*****************************************************************************/

#endif
