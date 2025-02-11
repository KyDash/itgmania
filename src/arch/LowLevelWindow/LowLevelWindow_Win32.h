#ifndef LOW_LEVEL_WINDOW_WIN32_H
#define LOW_LEVEL_WINDOW_WIN32_H

#include "LowLevelWindow.h"

class LowLevelWindow_Win32: public LowLevelWindow
{
public:
	LowLevelWindow_Win32();
	~LowLevelWindow_Win32();
	void *GetProcAddress( RString s );
	RString TryVideoMode( const VideoModeParams &p, bool &bNewDeviceOut );
	void GetDisplaySpecs( DisplaySpecs &out ) const;
	bool IsSoftwareRenderer( RString &sError );
	void SwapBuffers();
	void Update();
	bool SupportsThreadedRendering();
	void BeginConcurrentRendering();
	void EndConcurrentRendering();
	virtual bool SupportsRenderToTexture() const { return true; }
	virtual RenderTarget *CreateRenderTarget();

	bool SupportsFullscreenBorderlessWindow() const { return true; }

	const ActualVideoModeParams GetActualVideoModeParams() const;
};

#ifdef ARCH_LOW_LEVEL_WINDOW
#error "More than one LowLevelWindow selected!"
#endif
#define ARCH_LOW_LEVEL_WINDOW LowLevelWindow_Win32

#endif

/*
 * (c) 2004 Glenn Maynard
 * All rights reserved.
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, and/or sell copies of the Software, and to permit persons to
 * whom the Software is furnished to do so, provided that the above
 * copyright notice(s) and this permission notice appear in all copies of
 * the Software and that both the above copyright notice(s) and this
 * permission notice appear in supporting documentation.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT OF
 * THIRD PARTY RIGHTS. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR HOLDERS
 * INCLUDED IN THIS NOTICE BE LIABLE FOR ANY CLAIM, OR ANY SPECIAL INDIRECT
 * OR CONSEQUENTIAL DAMAGES, OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS
 * OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
 * OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */
