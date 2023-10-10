# Computação Gráfica

## Atividade 1 
A atividade foi feita com o auxílio da lib Image Magick++. Para sua instalação é necessário rodar o comando:
```
brew install imagemagick
```
Para rodar o projeto, é necessário entrar na pasta desejada e rodar o seguinte comando para compilar o arquivo nomeArquivo.cc:
```
g++ `Magick++-config --cxxflags --cppflags` -O2 -o nomeExecutável nomeArquivo.cc \ `Magick++-config --ldflags --libs`
```
Para gerar a imagem, basta rodar o executável:
```
./nomeExecutável
```
A imagem gerada será **nomeArquivo.png**
