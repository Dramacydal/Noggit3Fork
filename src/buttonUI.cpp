#include "buttonUI.h"
#include "noggit.h"

buttonUI::buttonUI( float pX, float pY, float w, float h, GLuint tex, GLuint texd )
{
	x = pX;
	y = pY;
	width = w;
	height = h;
	texture = tex;
	textureDown = texd;
	clickFunc = 0;
	id = 0;
	clicked = false;
	text = new textUI( w / 2.0f, 2.0f, &arial12, eJustifyCenter );
}

buttonUI::buttonUI( float pX, float pY, float w, float h, const std::string& pText, GLuint tex, GLuint texd )
{
	x = pX;
	y = pY;
	width = w;
	height = h;
	texture = tex;
	textureDown = texd;
	clickFunc = 0;
	id = 0;
	clicked = false;
	text = new textUI( w / 2.0f, 2.0f, pText, &arial12, eJustifyCenter );
}

buttonUI::buttonUI( float pX, float pY, float w, float h, const std::string& pTexNormal, const std::string& pTexDown )
{
	x = pX;
	y = pY;
	width = w;
	height = h;
	texture = video.textures.add( pTexNormal );
	textureDown = video.textures.add( pTexDown );
	clickFunc = 0;
	id = 0;
	clicked = false;
	text = new textUI( w / 2.0f, 2.0f, &arial12, eJustifyCenter );
}

buttonUI::buttonUI( float pX, float pY, float w, float h, const std::string& pText, const std::string& pTexNormal, const std::string& pTexDown )
{
	x = pX;
	y = pY;
	width = w;
	height = h;
	texture = video.textures.add( pTexNormal );
	textureDown = video.textures.add( pTexDown );
	clickFunc = 0;
	id = 0;
	clicked = false;
	text = new textUI( w / 2.0f, 2.0f, pText, &arial12, eJustifyCenter );
}

buttonUI::buttonUI( float pX, float pY, float w, float h, const std::string& pText, const std::string& pTexNormal, const std::string& pTexDown, void (*pFunc)( frame *, int ), int pFuncParam )
{
	x = pX;
	y = pY;
	width = w;
	height = h;
	texture = video.textures.add( pTexNormal );
	textureDown = video.textures.add( pTexDown );
	clickFunc = pFunc;
	id = pFuncParam;
	clicked = false;
	text = new textUI( w / 2.0f, 2.0f, pText, &arial12, eJustifyCenter );
}

void buttonUI::setLeft( )
{
	text->setJustify( eJustifyLeft );
	text->x = 10.0f;
}

void buttonUI::setText( const std::string& pText )
{
	text->setText( pText );
}

void buttonUI::setFont( freetype::font_data *font )
{
	text->setFont( font );
}
void buttonUI::render( )
{
	glPushMatrix( );
	glTranslatef( x, y, 0.0f );

	glColor3f( 1.0f, 1.0f, 1.0f );

	glActiveTexture( GL_TEXTURE0 );

	if( !clicked )
		glBindTexture( GL_TEXTURE_2D, texture );
	else
		glBindTexture( GL_TEXTURE_2D, textureDown );

	glEnable( GL_TEXTURE_2D );
		glBegin( GL_TRIANGLE_STRIP );
			glTexCoord2f( 0.0f, 0.0f );
			glVertex2f( 0.0f, 0.0f );
			glTexCoord2f( 1.0f, 0.0f );
			glVertex2f( width, 0.0f );
			glTexCoord2f( 0.0f, 1.0f );
			glVertex2f( 0.0f, height );
			glTexCoord2f( 1.0f, 1.0f );
			glVertex2f( width, height );
		glEnd( );
	glDisable( GL_TEXTURE_2D );
	
	text->render( );

	glPopMatrix( );
}

frame *buttonUI::processLeftClick( float mx, float my )
{
	clicked = true;
	if( clickFunc )
		clickFunc( this, id );
	return this;
}

void buttonUI::processUnclick( )
{
	clicked = false;
}

void buttonUI::setClickFunc( void (*f)( frame *, int ), int num )
{
	clickFunc = f;
	id = num;
}
