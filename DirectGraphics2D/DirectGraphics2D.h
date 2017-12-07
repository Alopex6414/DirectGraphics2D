/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2017, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		DirectGraphics2D.h
* @brief	This Program is DirectGraphics2D DLL Project.
* @author	Alopex/Helium
* @version	v1.00a
* @date		2017-11-2	v1.00a	alopex	Create Project
*/
#pragma once

#ifndef __DIRECTGRAPHICS2D_H_
#define __DIRECTGRAPHICS2D_H_

//Include Windows Header File
#include "DirectCommon.h"

//Macro Definition
#ifdef	DIRECTGRAPHICS2D_EXPORTS
#define DIRECTGRAPHICS2D_API	__declspec(dllexport)
#else
#define DIRECTGRAPHICS2D_API	__declspec(dllimport)
#endif

//Struct Definition
//Vertex 2D Base(2D���������ʽ)
struct Vertex2DBase
{
	float X, Y, Z, RHW;
	DWORD COLOR;
	Vertex2DBase(float x, float y, float z, float rhw, DWORD Color) :X(x), Y(y), Z(z), RHW(rhw), COLOR(Color) {}
};

#define D3DFVF_VERTEX2D_BASE	(D3DFVF_XYZRHW | D3DFVF_DIFFUSE)				//���������ʽģʽ(2D����/���������)

//Vertex 2D Texture(2D�������ʽ)
struct Vertex2DTexture
{
	float X, Y, Z, RHW;
	DWORD COLOR;
	float U, V;
	Vertex2DTexture(float x, float y, float z, float rhw, DWORD Color, float u, float v) :X(x), Y(y), Z(z), RHW(rhw), COLOR(Color), U(u), V(v) {}
};

#define D3DFVF_VERTEX2D_TEXTURE	(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)	//�������ʽģʽ(2D����/���������/����ͼ��)

//Vertex 2D Diffuse Specular Texture(2D���淴���������ʽ)
struct Vertex2DSpecularTexture
{
	float X, Y, Z, RHW;
	DWORD DIFFUSE;
	DWORD SPECULAR;
	float U, V;
	Vertex2DSpecularTexture(float x, float y, float z, float rhw, DWORD Diffuse, DWORD Specular, float u, float v) :X(x), Y(y), Z(z), RHW(rhw), DIFFUSE(Diffuse), SPECULAR(Specular), U(u), V(v) {}
};

#define D3DFVF_VERTEX2D_SPECULAR_TEXTURE	(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_SPECULAR | D3DFVF_TEX1)	//�����������ʽģʽ(2D����/���������/���淴�����/����ͼ��)

//Enum Definition
enum Vertex2DType
{
	Vertex2D_Type_Base = 0,				//Base����
	Vertex2D_Type_Texture = 1,			//Texture����
	Vertex2D_Type_Specular_Texture = 2,	//SpecularTexture����
};

//Class Definition
class DIRECTGRAPHICS2D_API DirectGraphics2D
{
protected:
	LPDIRECT3DDEVICE9 m_pD3D9Device;						//The Direct3D 9 Render Device 
	LPDIRECT3DVERTEXBUFFER9 m_pD3D9VertexBuffer;			//The Direct3D 9 Vertex Buffer
	LPDIRECT3DINDEXBUFFER9 m_pD3D9IndexBuffer;				//The Direct3D 9 Index  Buffer

private:
	LPDIRECT3DTEXTURE9 m_pD3D9Texture;						//The Direct3D 9 Texture


public:
	DirectGraphics2D();										//DirectGraphics2D Constructor Function(���캯��)
	~DirectGraphics2D();									//DirectGraphics2D Destructor  Function(��������)

	//����
	DirectGraphics2D(LPDIRECT3DDEVICE9 pD3D9Device);		//DirectGraphics2D Constructor Function(���캯��)(����D3D9 Device)(Important)

	//����
	LPDIRECT3DDEVICE9 WINAPI DirectGraphics2DGetD3D9Device(void) const;				//DirectGraphics2D D3D9 Get Device Pointer
	LPDIRECT3DVERTEXBUFFER9 WINAPI DirectGraphics2DGetVertexBuffer(void) const;		//DirectGraphics2D D3D9 Get Vertex Buffer
	LPDIRECT3DINDEXBUFFER9 WINAPI DirectGraphics2DGetIndexBuffer(void) const;		//DirectGraphics2D D3D9 Get Index Buffer
	LPDIRECT3DTEXTURE9 WINAPI DirectGraphics2DGetTexture(void) const;				//DirectGraphics2D D3D9 Get Texture

	//����
	void WINAPI DirectGraphics2DSetD3D9Device(LPDIRECT3DDEVICE9 pD3D9Device);					//DirectGraphics2D D3D9 Set Device Pointer
	void WINAPI DirectGraphics2DSetVertexBuffer(LPDIRECT3DVERTEXBUFFER9 pD3D9VertexBuffer);		//DirectGraphics2D D3D9 Set Vertex Buffer
	void WINAPI DirectGraphics2DSetIndexBuffer(LPDIRECT3DINDEXBUFFER9 pD3D9IndexBuffer);		//DirectGraphics2D D3D9 Set Index Buffer
	void WINAPI DirectGraphics2DSetTexture(LPDIRECT3DTEXTURE9 pD3D9Texture);					//DirectGraphics2D D3D9 Set Texture

	//��ʼ��
	virtual HRESULT WINAPI DirectGraphics2DInit(int nPlane);														//DirectGraphics2D Initialization(��ʼ��)(ƽ����)
	virtual HRESULT WINAPI DirectGraphics2DInit(int nPlane, LPCWSTR lpszStrTexture);								//DirectGraphics2D Initialization(��ʼ��)(ƽ����/����)
	virtual HRESULT WINAPI DirectGraphics2DInit(Vertex2DType eVertex2DType, int nPlane);							//DirectGraphics2D Initialization(��ʼ��)(��������/ƽ����)
	virtual HRESULT WINAPI DirectGraphics2DInit(Vertex2DType eVertex2DType, int nPlane, LPCWSTR lpszStrTexture);	//DirectGraphics2D Initialization(��ʼ��)(��������/ƽ����/����)

	//���
	//����
	virtual void WINAPI DirectGraphics2DPaddingVertex(Vertex2DBase* VertexArray, int nSize);						//DirectGraphics2D Padding Vertex(��䶥������)(2D���������ʽ)
	virtual void WINAPI DirectGraphics2DPaddingVertex(Vertex2DTexture* VertexArray, int nSize);						//DirectGraphics2D Padding Vertex(��䶥������)(2D���������ʽ)
	virtual void WINAPI DirectGraphics2DPaddingVertex(Vertex2DSpecularTexture* VertexArray, int nSize);				//DirectGraphics2D Padding Vertex(��䶥������)(2D���㾵�������ʽ)

	//����
	virtual void WINAPI DirectGraphics2DPaddingIndex(int nPlane);													//DirectGraphics2D Padding Index(�����������)

	//All
	virtual void WINAPI DirectGraphics2DPaddingVertexAndIndex(Vertex2DBase* VertexArray, int nPlane);							//DirectGraphics2D Padding Vertex and Index(��䶥�����������)
	virtual void WINAPI DirectGraphics2DPaddingVertexAndIndex(Vertex2DTexture* VertexArray, int nPlane);						//DirectGraphics2D Padding Vertex and Index(��䶥�����������)
	virtual void WINAPI DirectGraphics2DPaddingVertexAndIndex(Vertex2DSpecularTexture* VertexArray, int nPlane);				//DirectGraphics2D Padding Vertex and Index(��䶥�����������)
	virtual void WINAPI DirectGraphics2DPaddingVertexAndIndex(Vertex2DType eVertex2DType, LPVOID VertexArray, int nPlane);		//DirectGraphics2D Padding Vertex and Index(��䶥�����������)

	//��Ⱦ
	//��Ⱦģʽ
	virtual void WINAPI DirectGraphics2DRenderStateAlphaEnable(void);															//DirectGraphics2D Render State Setting(����Alpha���)//��Ⱦ��Ϲر�Alpha���
	virtual void WINAPI DirectGraphics2DRenderStateAlphaDisable(void);															//DirectGraphics2D Render State Setting(�ر�Alpha���)
	virtual void WINAPI DirectGraphics2DRenderStateSetting(void);																//DirectGraphics2D Render State Setting
	virtual void WINAPI DirectGraphics2DRenderStateAlphaMix(void);																//DirectGraphics2D Render State Setting(Alpha�ں�����)
	virtual void WINAPI DirectGraphics2DRenderStateColorMix(void);																//DirectGraphics2D Render State Setting(Color�ں�����)(ѡ��)
	virtual void WINAPI DirectGraphics2DRenderStateColorMix(D3DXCOLOR MixColor);												//DirectGraphics2D Render State Setting(Color�ں�����)(���)

	//����
	virtual void WINAPI DirectGraphics2DRender(Vertex2DType eVertex2DType, int nPlane, bool bIsTexture = false);											//DirectGraphics2D Render(��Ⱦ)
	virtual void WINAPI DirectGraphics2DRender(Vertex2DType eVertex2DType, int nStartIndex, int nPlane, bool bIsTexture = false);							//DirectGraphics2D Render(��Ⱦ)
	virtual void WINAPI DirectGraphics2DRender(Vertex2DType eVertex2DType, int nStartIndex, int nPlane, LPDIRECT3DTEXTURE9 pRenderTexture);					//DirectGraphics2D Render(��Ⱦ)
};

#endif