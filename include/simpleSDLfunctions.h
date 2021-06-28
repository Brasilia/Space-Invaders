#ifndef SIMPLESDLFUNCTIONS_H_INCLUDED
#define SIMPLESDLFUNCTIONS_H_INCLUDED

//################################## FUN��ES DE ATALHO ##################################OO
//Fun��es para facilitar a aplica��o de outras fun��es, otimizando suas utiliza��es,
//em termos de organiza��o e linhas de c�digo

//---------------------------------- CARREGAR IMAGEM ------------------------------------//
//Fun��o de carregamento de imagem
SDL_Surface *load_image(const char *nome_do_arquivo)
{
    //Ponteiro de armazenamento de imagem
    SDL_Surface *imagem = NULL;

    //Carregar imagem
    imagem = IMG_Load(nome_do_arquivo);
    //Se a imagem tiver sido carregada corretamente
    if (imagem != NULL)
    {
        //Otimizar a imagem
        imagem = SDL_DisplayFormat(imagem);

        //Definir cor chave
        Uint32 corchave = SDL_MapRGB(imagem->format, 0xFF, 0, 0xFF);

        //Tornar a cor chave transparente
        SDL_SetColorKey(imagem, SDL_SRCCOLORKEY, corchave);
    }

    //Retorna a imagem otimizada
    return imagem;
}
//---------------------------------------------------------------------------------------//

//--------------------------------- APLICAR SUPERFICIE ----------------------------------//
//Aplica uma superf�cie recebendo tamb�m suas coordenadas como par�metros
void apply_surface(int x, int y, SDL_Surface* fonte, SDL_Surface* destino, SDL_Rect* corte = NULL, float empurrar = 0)
{
    //Especifica as coordenadas x e y da superf�cie
    SDL_Rect coordenada;
    coordenada.x = x;
    coordenada.y = y;

    coordenada.x -= fonte->w*empurrar;

    //Transferir superf�cie para seu destino
    SDL_BlitSurface(fonte, corte, destino, &coordenada);
}
//---------------------------------------------------------------------------------------//

//--------------------------------- ESCREVER TEXTO --------------------------------------//
//Escreve um texto na tela, na posi��o desejada
//void write_text(int x, int y, char texto[])
//{
//    mensagem_texto = TTF_RenderText_Solid(fonte, texto, cortexto);
//    aplicar_superficie(x, y, mensagem_texto, tela);
//}
//---------------------------------------------------------------------------------------//
#endif // SIMPLESDLFUNCTIONS_H_INCLUDED
