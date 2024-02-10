#include "obj.h"
#include "gtest/gtest.h"

TEST(ObjectReaderTest, ReadObj) {
    objectReader reader;
    reader.readObj();
    int numVertices = reader.getNumVertices();
    // substituir 0 pelo número esperado de vértices no arquivo cat_obj/cat.obj (não esquecer de contar o número de vértices no arquivo)
    EXPECT_EQ(numVertices, 0);
}