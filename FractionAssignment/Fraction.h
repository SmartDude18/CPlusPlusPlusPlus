#pragma once
#include <iostream>
#include <string>
template <typename T>
class Fraction 
{
	private:
		T numerator = 0;
		T denominator = 0;
	public:
		//IO
		friend std::ostream& operator<<(std::ostream& os, const Fraction<T>& frac)
		{
			os << frac.numerator << "/" << frac.denominator;
			return os;
		}

		friend std::istream& operator>>(std::istream& is, Fraction<T>& frac)
		{
			T holdVal;
			std::cout << "Enter the numerator" << std::endl;
			is >> holdVal;

			frac.setNumerator(holdVal);
			std::cout << "Enter the denominator" << std::endl;
			is >> holdVal;
			frac.setDenominator(holdVal);
			frac.simplify();
			return is;
		}
		//Comparatives

		friend bool operator<(const Fraction<T>& fracToComp1, const Fraction<T>& fracToComp2)
		{
			if ((fracToComp1.numerator * fracToComp2.denominator) < (fracToComp2.numerator * fracToComp1.denominator))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		friend bool operator>(const Fraction<T>& fracToComp1, const Fraction<T>& fracToComp2)
		{
			if ((fracToComp1.numerator * fracToComp2.denominator) > (fracToComp2.numerator * fracToComp1.denominator))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		friend bool operator<=(const Fraction<T>& fracToComp1, const Fraction<T>& fracToComp2)
		{
			
			if ((fracToComp1.numerator * fracToComp2.denominator) <= (fracToComp2.numerator * fracToComp1.denominator))
			{
				return true;
			}
			else
			{
				return false;
			}
			
		}
		friend bool operator>=(const Fraction<T>& fracToComp1, const Fraction<T>& fracToComp2)
		{
			if ((fracToComp1.numerator * fracToComp2.denominator) >= (fracToComp2.numerator * fracToComp1.denominator))
			{
				return true;
			}
			else
			{
				return false;
			}
		}


		friend bool operator==(const Fraction<T>& fracToComp1, const Fraction<T>& fracToComp2)
		{
			if (fracToComp1.numerator == fracToComp2.numerator && fracToComp1.denominator == fracToComp2.denominator)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		friend bool operator!=(const Fraction<T>& fracToComp1, const Fraction<T>& fracToComp2)
		{
			if (fracToComp1.numerator == fracToComp2.numerator && fracToComp1.denominator == fracToComp2.denominator)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
		Fraction(T newNumerator, T newDenominator)
		{
			numerator = newNumerator;
			denominator = newDenominator;
			simplify();
		}
		Fraction(){}
		double toDouble()
		{
			double holdDouble = (numerator / (double)denominator);
			return holdDouble;
		}
		const T getNumerator() { return numerator; }
		const T getDenominator() { return denominator; }
		void simplify()
		{
			if (denominator == 0)
			{
				numerator = 0;
				return;
			}
			bool isNeg = false;
			if (numerator < 0)
			{
				isNeg = !isNeg;
				numerator *= -1;
			}
			if (denominator < 0)
			{
				isNeg = !isNeg;
				denominator *= -1;
			}
			T checkNum = std::min(numerator, denominator);
			while (checkNum > 1)
			{
				if (numerator % checkNum == 0 && denominator % checkNum == 0)
				{
					numerator /= checkNum;
					denominator /= checkNum;
					break;
				}
				checkNum--;
			}
			if (isNeg)
			{
				numerator *= -1;
			}
		}
		void setNumerator(T val)
		{
			if (val != NULL)
			{
				numerator = val;
			}
		}
		void setDenominator(T val)
		{
			if (val != NULL)
			{
				if (val != 0)
				{
					denominator = val;
				}
			}
		}
};


//Math
template <typename T>
Fraction<T> operator +(Fraction<T>& fracToAdd1, Fraction<T>& fracToAdd2)
{
	T holdNum1 = fracToAdd1.getNumerator() * fracToAdd2.getDenominator();
	T holdNum2 = fracToAdd2.getNumerator() * fracToAdd1.getDenominator();
	T holdDenom = fracToAdd1.getDenominator() * fracToAdd2.getDenominator();
	Fraction<T> holdFrac(holdNum1 + holdNum2, holdDenom);
	holdFrac.simplify();
	return holdFrac;
}
template <typename T>
Fraction<T> operator -(Fraction<T>& fracToSub1, Fraction<T>& fracToSub2)
{
	T holdNum1 = fracToSub1.getNumerator() * fracToSub2.getDenominator();
	T holdNum2 = fracToSub2.getNumerator() * fracToSub1.getDenominator();
	T holdDenom = fracToSub1.getDenominator() * fracToSub2.getDenominator();
	Fraction<T> holdFrac(holdNum1 - holdNum2, holdDenom);
	holdFrac.simplify();
	return holdFrac;
}
template <typename T>
Fraction<T> operator *(Fraction<T>& fracToMult1, Fraction<T>& fracToMult2)
{
	Fraction<T> holdFrac(fracToMult1.getNumerator() * fracToMult2.getNumerator(), fracToMult1.getDenominator() * fracToMult2.getDenominator());
	holdFrac.simplify();
	return holdFrac;
}
template <typename T>
Fraction<T> operator/(Fraction<T>& fracToDiv1, Fraction<T>& fracToDiv2)
{
	if (fracToDiv2.getNumerator() == 0)
	{
		return Fraction<T>(0,0);
	}
	Fraction<T> holdFrac(fracToDiv1.getNumerator() * fracToDiv2.getDenominator(), fracToDiv1.getDenominator() * fracToDiv2.getNumerator());
	holdFrac.simplify();
	return holdFrac;
}


