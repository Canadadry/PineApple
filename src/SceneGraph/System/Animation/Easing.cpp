/*
 *  Easing.cpp
 *  SECA
 *
 *  Created by Canadadry on 17/01/11.
 *
 *  This software is provided 'as-is', without any express or
 *  implied warranty. In no event will the authors be held
 *  liable for any damages arising from the use of this software.
 *
 *  Permission is granted to anyone to use this software for any purpose,
 *  including commercial applications, and to alter it and redistribute
 *  it freely, subject to the following restrictions:
 *
 *  1. The origin of this software must not be misrepresented;
 *     you must not claim that you wrote the original software.
 *     If you use this software in a product, an acknowledgment
 *     in the product documentation would be appreciated but
 *     is not required.
 *
 *  2. Altered source versions must be plainly marked as such,
 *     and must not be misrepresented as being the original software.
 *
 *  3. This notice may not be removed or altered from any
 *     source distribution.
 *
 */
#include "Easing.h"
#include <math.h>

const float PI = 3.1415926535;

const Easing Easing::REGULAR_IN(In,Quadradic);
const Easing Easing::REGULAR_OUT(Out,Quadradic);
const Easing Easing::REGULAR_IN_OUT(In_Out,Quadradic);

const Easing Easing::STRONG_IN(In,Quintic);
const Easing Easing::STRONG_OUT(Out,Quintic);
const Easing Easing::STRONG_IN_OUT(In_Out,Quintic);

const Easing Easing::BACK_IN(In,Back);
const Easing Easing::BACK_OUT(Out,Back);
const Easing Easing::BACK_IN_OUT(In_Out,Back);

const Easing Easing::ELASTIC_IN(In,Elastic);
const Easing Easing::ELASTIC_OUT(Out,Elastic);
const Easing Easing::ELASTIC_IN_OUT(In_Out,Elastic);

Easing::Easing(Type type, Function function)
: m_type(type)
,m_func(function)
{}

float Easing::ease(float t) const
{
    double easedT;
    if(t>=1) t=1;

    switch (m_type)
    {
        default:
            easedT = t;
            break;

        case In:
            easedT = applyFunction(t);
            break;

        case Out:
            easedT = 1-applyFunction(1-t);
            break;

        case In_Out:
            if (t < 0.5) {
                easedT = applyFunction(2*t)/2;
            }
            else {
                easedT = 1-applyFunction(2 - 2*t)/2;
            }
            break;
        }

        return easedT;
}

float Easing::applyFunction(float t) const
{
    double t2;
    double t3;

    switch (m_func)
    {
        default: ;
        case Linear:
            return t;

        case Quadradic:
            return t * t;

        case Cubic:
            return t * t * t;

        case Quartic:
            t2 = t * t;
            return t2 * t2;

        case Quintic:
            t2 = t * t;
            return t2 * t2 * t;

        case Back:
            t2 = t * t;
            t3 = t2 * t;
            return t3 + t2 - t;

        case Elastic:
            t2 = t * t;
            t3 = t2 * t;

            double scale = t2 * (2*t3 + t2 - 4*t + 2);
            double wave = (float)-sin(t * 3.5 * PI);

            return scale * wave;
    }
}

