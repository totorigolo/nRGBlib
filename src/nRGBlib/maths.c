/*****************************************************************************
 * Copyright (C) 2010 by ANNEHEIM Geoffrey
 * Contact: geoffrey.anneheim@gmail.com
 *
 * Original code by BoneSoft:
 * http://www.codeproject.com/KB/GDI-plus/FunWithGravity.aspx
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * RCSID $Id$
 *****************************************************************************/
#include <nMATHS.h>
#include <os.h>

/// Choose a SEmi-RANDom number (based on the number of times this function is called -> the results are always the same ;D)
int serand()
{
    static int m_w = 56789;
    static int m_z = 38765;

    m_z = 36969 * (m_z & 65535) + (m_z >> 16);
    m_w = 18000 * (m_w & 65535) + (m_w >> 16);

    return (m_z << 16) + m_w;
}
/// \min included et \max included
int randMinMax(int min, int max)
{
    return abs(rand()) % (max - min + 1) + min;
}
int serandMinMax(int min, int max)
{
    return abs(serand()) % (max - min + 1) + min;
}
