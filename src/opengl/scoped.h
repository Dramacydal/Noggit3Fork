#ifndef __OPENGL_SCOPED_H
#define __OPENGL_SCOPED_H

#include <opengl/texture.h>

namespace opengl
{
  namespace scoped
  {
    //! \todo Ensure the if is done at compile time by template spezialization.
    template<GLenum cap, GLboolean value>
    class bool_setter
    {
    public:
      bool_setter()
        : _was_enabled (glIsEnabled (cap) == GL_TRUE)
      {
        if (value == GL_TRUE)
        {
          glEnable (cap);
        }
        else
        {
          glDisable (cap);
        }
      }

      ~bool_setter()
      {
        if (_was_enabled == GL_TRUE)
        {
          glEnable (cap);
        }
        else
        {
          glDisable (cap);
        }
      }

    private:
      bool _was_enabled;
    };

    template<GLenum texture_number, GLboolean value>
    class texture_setter
    {
    public:
      texture_setter()
        : _was_enabled (false)
      {
        texture::set_active_texture (texture_number);
        _was_enabled = (glIsEnabled (GL_TEXTURE_2D) == GL_TRUE);
        if (value == GL_TRUE)
        {
          glEnable (GL_TEXTURE_2D);
        }
        else
        {
          glDisable (GL_TEXTURE_2D);
        }
      }

      ~texture_setter()
      {
        texture::set_active_texture (texture_number);
        if (_was_enabled == GL_TRUE)
        {
          glEnable (GL_TEXTURE_2D);
        }
        else
        {
          glDisable (GL_TEXTURE_2D);
        }
      }

    private:
      bool _was_enabled;
    };

    class matrix_pusher
    {
    public:
      matrix_pusher()
      {
        glPushMatrix();
      }
      ~matrix_pusher()
      {
        glPopMatrix();
      }
    };

    class name_pusher
    {
    public:
      name_pusher (GLuint name_id)
      {
        glPushName (name_id);
      }
      ~name_pusher()
      {
        glPopName();
      }
    };
  }
}

#endif