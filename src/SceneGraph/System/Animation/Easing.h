/*
 *  Easing.h
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

#ifndef _Easing_H_
#define _Easing_H_

enum Type {In,Out,In_Out };

enum Function
{
    Linear,
    Quadradic,
    Cubic,
    Quartic,
    Quintic,
    Back,
    Elastic
};

class Easing
{
    public:
        Easing(Type type = In, Function function = Linear);
        float ease(float t) const;

        static const Easing REGULAR_IN;
        static const Easing REGULAR_OUT;
        static const Easing REGULAR_IN_OUT;

        static const Easing STRONG_IN;
        static const Easing STRONG_OUT;
        static const Easing STRONG_IN_OUT;

        static const Easing BACK_IN;
        static const Easing BACK_OUT;
        static const Easing BACK_IN_OUT;

        static const Easing ELASTIC_IN;
        static const Easing ELASTIC_OUT;
        static const Easing ELASTIC_IN_OUT;

    protected:
        virtual float applyFunction(float t) const;

    private:
        Type     m_type;
        Function m_func;
};

#endif //end of Easing
