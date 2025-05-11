#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB_12.1/lab_12.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LinkedDataTests
{
    TEST_CLASS(StructureTests)
    {
    public:
        TEST_METHOD(TestBuildAndDestroy)
        {
            // Оголошуємо п'ять покажчиків
            Node* p, * n1, * n2, * n3, * n4;

            // Будуємо структуру
            BuildStructure(p, n1, n2, n3, n4);

            // Перевіряємо, що всі вузли створені
            Assert::IsNotNull(p);
            Assert::IsNotNull(n1);
            Assert::IsNotNull(n2);
            Assert::IsNotNull(n3);
            Assert::IsNotNull(n4);

            // Перевіряємо зв’язки згідно схеми
            Assert::IsTrue(p->next1 == n1);

            Assert::IsTrue(n1->next1 == n2);
            Assert::IsTrue(n1->next2 == n4);

            Assert::IsNull(n2->next1);
            Assert::IsTrue(n2->next2 == n3);

            Assert::IsTrue(n3->next1 == n2);
            Assert::IsNull(n3->next2);

            Assert::IsTrue(n4->next1 == n1);
            Assert::IsTrue(n4->next2 == n3);

            // Руйнуємо структуру
            DestroyStructure(p, n1, n2, n3, n4);

            // Після руйнування всі покажчики мають стати nullptr
            Assert::IsNull(p);
            Assert::IsNull(n1);
            Assert::IsNull(n2);
            Assert::IsNull(n3);
            Assert::IsNull(n4);
        }
    };
}
