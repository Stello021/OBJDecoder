#pragma once

#include <iostream>

template <class T> struct Vector2
{
	union
	{
		struct
		{
			T U, V;
		};

		struct
		{
			T X, Y;
		};

		T Raw[2];
	};

	Vector2() : U(0), V(0)
	{

	}

	Vector2(T u, T v)  :  U(u), V(v)
	{

	}

	inline Vector2<T> operator+ (const Vector2<T>& v) const { return Vector2<T>(U + v.U, V + v.V); }
	inline Vector2<T> operator- (const Vector2<T>& v) const { return Vector2<T>(U - v.U, V - v.V); }
	inline Vector2<T> operator* (const float f) const { return Vector2<T>(U * f, V * f); }

	template <class > friend std::ostream& operator<< (std::ostream& s, Vector2<T>& v); //this operator refer to following function

};

template <class T> std::ostream& operator<< (std::ostream& s, Vector2<T>& v)
{
	s << "(" << v.U << ", " << v.V << ")";
	return s;
};

template <class T> struct Vector3
{
	union
	{
		struct
		{
			T VertexIndeces, UVIndeces, NormalIndeces;
		};

		struct
		{
			T X, Y, Z;
		};

		T Raw[3];
	};

	Vector3() : X(0), Y(0), Z(0)
	{

	}

	Vector3(T x, T y, T z) : X(x), Y(y), Z(z)
	{

	}

	inline Vector3<T> operator+ (const Vector3<T>& v) const { return Vector2<T>(X + v.X, Y + v.Y, Z + v.Z); }
	inline Vector3<T> operator- (const Vector3<T>& v) const { return Vector2<T>(X - v.X, Y - v.Y, Z - v.Z); }
	inline Vector3<T> operator* (const float f) const { return Vector2<T>(X * f, Y * f, Z * f); }
	inline T operator* (const Vector3<T>& v) const { return X * v.X + Y * v.Y + Z * v.Z } //Dot Product
	inline Vector3<T> operator^ (const Vector3<T>& v) const //Cross Product
	{ 
		return Vector3<T> (Y * v.Z - Z * v.Y, Z * v.X - X * v.Z, X * v.Y - Y * v.X)
	} 

	T Dot(const Vector3<T>& v) const
	{
		T result = *this * v;
		return result;
	}

	Vector3<T> Cross(const Vector3<T>& v) const
	{
		Vector3<T> result = *this ^ v;
		return result;
	}

	/// <summary>
	/// Calculates vector's length
	/// </summary>
	float Magnitude() const
	{
		return std::sqrt(X * X + Y * Y + Z * Z);
	}

	/// <summary>
	/// Scales the vector to have a magnitude of lenght
	/// </summary>
	Vector3<T>& Normalize(T length = 1)
	{
		*this *= length / Magnitude();
		return *this;
	}

	template <class> friend std::ostream& operator<<(std::ostream& s, Vector3<t>& v); //this operator refer to following function
};

template <class T> 	std::ostream& operator<< (std::ostream& s, Vector3<T>& v) 
{
	s << "(" << v.X << ", " << v.Y << ", " << v.Z << ")";
	return s;
};
