#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\HP\source\repos\Lab 10.1 a\Lab 10.1 a\source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			Student students[3];

			students[0].data.grades.physics = 5;
			students[0].data.grades.math = 4;
			students[0].data.grades.informatics = 4;

			students[1].data.grades.physics = 4;
			students[1].data.grades.math = 4;
			students[1].data.grades.informatics = 5;

			students[2].data.grades.physics = 4;
			students[2].data.grades.math = 4;
			students[2].data.grades.informatics = 4;

			int expected = 3;
			int actual = countExcellentAndGoodStudents(students, 3);
			Assert::AreEqual(expected, actual);

		};
	};
}
