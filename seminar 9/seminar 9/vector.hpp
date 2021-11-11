#pragma once
#include <iostream>
#include <vector>


namespace My_space
{

	template < typename T >
	class Vector
	{
	public:

		using value_type = T;
		using pointer = T*;
		using const_pointer = const T*;
		using reference = T&;
		using const_reference = const T&;
		using size_type = std::size_t;

		using iterator = pointer;
		using const_iterator = const_pointer;

	public:

		Vector() = default;

		explicit Vector(size_type size);
		explicit Vector(size_type size, const T& initial);
		Vector(const std::vector<T>& vector);
		Vector(const Vector& other);
		Vector(Vector&& other);
		Vector& operator=(const Vector&);
		Vector& operator=(Vector&& other);
		std::size_t size()
		{
			return m_size;
		}

		std::size_t capacity()
		{
			return m_capacity;
		}


		~Vector() noexcept
		{
			delete[] m_data;
		}

	public:

		reference operator[] (size_type index)
		{
			if (index >= m_size)
			{
				throw std::out_of_range("Out of range");
			}
			return m_data[index];
		}

		const_reference operator[](size_type index) const noexcept
		{
			if (index >= m_size)
			{
				throw std::out_of_range("Out of range");
			}
			return m_data[index];
		}
		

		reference front()
		{
			if (!m_size)
			{
				throw std::out_of_range("Out of range");
			}
			return m_data[0];
		}

		reference back()
		{
			if (!m_size)
			{
				throw std::out_of_range("Out of range");
			}
			return m_data[m_size - 1];
		}

		const_reference front() const
		{
			if (!m_size)
			{
				throw std::out_of_range("Out of range");
			}
			return m_data[0];
		}
		const_reference back() const
		{
			if (!m_size)
			{
				throw std::out_of_range("Out of range");
			}
			return m_data[m_size - 1];
		}

		iterator begin() noexcept
		{
			return m_data;
		}
		iterator end() noexcept
		{
			return m_data + m_size; // на элемент следующий за последним
		}

		const_iterator begin() const noexcept
		{
			return m_data;
		}
		const_iterator end() const noexcept
		{
			return m_data + m_size;
		}
		size_type size() const noexcept
		{
			return m_size;
		}
		size_type capacity() const noexcept
		{
			return m_capacity;
		}
		void resize(std::size_t size);
		void resize(std::size_t size, T&);
		void push_back(const T& value);
		void pop_back();

	private:
		pointer m_data{ nullptr };
		size_type m_size{ 0 };
		size_type m_capacity{ 0 };
		pointer allocate_memory(size_type size);
	};




	template <typename T>
	T* Vector <T> ::allocate_memory(size_type size)
	{
		try
		{
			m_data = new T[size];
		}
		catch (const std::bad_alloc& ba)
		{
			if (m_data)
			{
				delete[] m_data;
			}
			std::cerr << "bad_alloc caught: " << ba.what() << '\n';
		}
		catch (...)
		{
			if (m_data)
			{
				delete[] m_data;
			}
		}
		return m_data;
	}

	template < typename T >
	Vector < T > ::Vector(size_type size) : m_size{ size }, m_capacity{ size }
	{
		m_data = allocate_memory(m_size);
	}

	template < typename T >
	Vector < T > ::Vector(size_type size, const T& initial) : m_size{ size }, m_capacity{ size }
	{
		m_data = allocate_memory(m_size);
		for (auto i = 0U; i < m_size; ++i)
		{
			m_data[i] = initial;
		}
	}

	template < typename T >
	Vector < T >::Vector(const Vector < T >& other) : m_size{ other.m_size }, m_capacity{ other.m_capacity }
	{
		m_data = allocate_memory(m_size);
		std::copy(other.begin(), other.end(), m_data);
	}

	template < typename T >
	Vector < T >::Vector(Vector < T >&& other) : m_size{ other.m_size },
		m_capacity{ other.m_capacity }, m_data{ other.m_data }
	{
		other.m_size = 0;
		other.m_capacity = 0;
		other.m_data = nullptr;
	}

	template < typename T >
	Vector < T > ::Vector(const std::vector < T >& vector) : m_size{ vector.size() }, m_capacity{ m_size }
	{
		m_data = allocate_memory(m_size);
		for (auto i = 0u; i < m_size; ++i)
		{
			m_data[i] = vector[i];
		}
	}


	template < typename T >
	Vector < T >& Vector < T > ::operator= (const Vector<T>& other)
	{
		if (this == &other) return *this;
		delete[] m_data;
		m_size = other.m_size;
		m_capacity = other.m_capacity;
		m_data = allocate_memory(m_size);
		std::copy(other.begin(), other.end(), m_data);
		return *this;
	}



	template < typename T >
	void Vector<T>::push_back(const T& value)
	{
		if (m_size >= m_capacity)
		{
			auto new_capacity = (m_capacity == 0) ? 1 : 2 * m_capacity;
			T* new_data = new T[new_capacity];
			std::copy(this->begin(), this->end(), new_data);
			delete[] m_data;
			m_data = new_data;
			m_capacity = new_capacity;
		}
		m_data[m_size++] = value;
	}

	template < typename T >
	void Vector<T>::pop_back()
	{
		if (!m_size)
		{
			throw std::out_of_range("Out of range");
		}
		m_size--;
	}

	template < typename T >
	void Vector<T>::resize(std::size_t new_size)
	{
		if (new_size >= m_capacity)
		{
			std::size_t new_capacity = new_size;
			T* new_data = allocate_memory(new_capacity);

			std::copy(this->begin(), this->end(), new_data);
			delete[] m_data;

			for (std::size_t i = m_size; i < new_size; ++i)
			{
				T t;
				new_data[i] = t;
			}
			m_data = new_data;
			m_capacity = new_capacity;
		}
		m_size = new_size;
	}


	template < typename T >
	void Vector<T>::resize(std::size_t new_size, T& def_value)
	{
		if (new_size >= m_capacity)
		{
			std::size_t new_capacity = new_size;
			T* new_data = allocate_memory(new_capacity);

			std::copy(this->begin(), this->end(), new_data);
			delete[] m_data;

			for (std::size_t i = m_size; i < new_size; ++i)
			{
				T t;
				new_data[i] = t;
			}
			m_data = new_data;
			m_capacity = new_capacity;
		}
		m_size = new_size;
	}

	template < typename T>
	void swap(T& v1, T& v2) noexcept
	{
		T tmp = std::move(v1);
		v1 = std::move(v2);
		v2 = std::move(tmp);
	};

}