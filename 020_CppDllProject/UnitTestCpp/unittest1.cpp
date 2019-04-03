#include "stdafx.h"
#include "CppUnitTest.h"

#include "DllTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestCpp
{		
	TEST_CLASS(UnitTest1)
	{
	public:

		BEGIN_TEST_METHOD_ATTRIBUTE(TestMethod_Normal)
			TEST_PRIORITY(1)
			TEST_DESCRIPTION(L"description1")
			TEST_WORKITEM(11)
		END_TEST_METHOD_ATTRIBUTE()

		TEST_METHOD(TestMethod_Normal)
		{
			wchar_t* buf_in = L"����������";
			wchar_t* buf_out = nullptr;

			int ans1 = Test_MyApiAdd(1, 2);
			int ans2 = Test_MyApiSub(3, 1);
			Test_MyApiPointerCopy(buf_in, &buf_out);

			Assert::AreEqual(ans1, 1 + 2); // ����ɏI��
			Assert::AreEqual(ans2, 3 - 1); // ����ɏI��
			Assert::IsNotNull(buf_out);    // ����ɏI��

			Logger::WriteMessage("Test OK");// �f�o�b�O���̃��O(�o�͗�)�ɏo��
		}

		BEGIN_TEST_METHOD_ATTRIBUTE(TestMethod_Error)
			TEST_PRIORITY(2)
			TEST_DESCRIPTION(L"description2")
			TEST_WORKITEM(12)
		END_TEST_METHOD_ATTRIBUTE()

		TEST_METHOD(TestMethod_Error)
		{
			wchar_t* buf_in = nullptr;
			wchar_t* buf_out = nullptr;

			int ans1 = Test_MyApiAdd(1, 2);
			int ans2 = Test_MyApiSub(3, 1);
			Test_MyApiPointerCopy(buf_in, &buf_out);

			Assert::AreEqual(ans1, 1 + 5);    // ans1��1+5����v���Ȃ��̂ŁA������Test�X�g�b�v�B
			Assert::AreEqual(ans2, 100 - 1);  // ���{����Ȃ�
			Assert::IsNotNull(buf_out);       // ���{����Ȃ�

			Logger::WriteMessage("Test OK");
		}
	};
}
