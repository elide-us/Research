//
// pch.h
// Header for standard system include files.
//

#pragma once

#include <WinSDKVer.h>
#define _WIN32_WINNT 0x0600
#include <SDKDDKVer.h>

// Use the C++ standard templated min/max
#define NOMINMAX

// DirectX apps don't need GDI
#define NODRAWTEXT
#define NOGDI
#define NOBITMAP

// Include <mcx.h> if you need this
#define NOMCX

// Include <winsvc.h> if you need this
#define NOSERVICE

// WinHelp is deprecated
#define NOHELP

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <wrl/client.h>

#include <d3d11_1.h>
#include <DirectXMath.h>
#include <DirectXColors.h>

#include <algorithm>
#include <exception>
#include <memory>
#include <stdexcept>

#include "CommonStates.h"
#include "DDSTextureLoader.h"
#include "DirectXHelpers.h"
#include "Effects.h"
#include "GamePad.h"
#include "GeometricPrimitive.h"
#include "GraphicsMemory.h"
#include "Keyboard.h"
#include "Model.h"
#include "Mouse.h"
#include "PrimitiveBatch.h"
#include "ScreenGrab.h"
#include "SimpleMath.h"
#include "SpriteBatch.h"
#include "SpriteFont.h"
#include "VertexTypes.h"
#include "WICTextureLoader.h"

#include "PhysicsMain.h"                    // Implements physics system
#include "ClipmapView.h"                    // Implements camera view system
#include "Generator.h"                      // Implements the cell generation system

#include "MaterialLibrary.h"                //
#include "VoxelLayer.h"                     //
#include "Clipboard.h"                      // Fast Memento pattern for Voxel Data

#include "InstanceManager.h"                // Mesh objects
#include "ArchitectureManager.h"            // Prefab expressions
#include "HydroTile.h"                      // Water ?
#include "TileSet.h"                        // 

#include "Biome.h"                          // Implements a simplex world

#include "ClientChannel.h"                  // Client IO class (Use this for client compoents)
#include "ServerChannel.h"                  // Server IO class (Use this for server components)
#include "VoxelDB.h"                        // Implements data storage system

/*
// VoxelFarmLibrary Interfaces
#include "ArchitectureManager.h"
#include "BitStream.h"
#include "BlockData.h"
#include "BoxMeshStamp.h"
#include "BundleDataByteParser.h"
#include "BundleProject.h"
#include "CellData.h"
#include "CellSeams.h"
#include "ClipboardData.h"
#include "contour.h"
#include "DetailTransfer.h"
#include "DetailTransferMesh.h"
#include "DetailTransferProjection.h"
#include "DetailTransferPropertyBag.h"
#include "DetailTransferStreamingMeshInterface.h"
#include "DetailTransferTexture.h"
#include "DetailTransferUtil.h"
#include "DetailTransferUV.h"
#include "extension.h"
#include "ExtensionLayer.h"
#include "ExternalMutex.h"
#include "ExternalRWLock.h"
#include "ExternalTiming.h"
#include "FastQuadrics.h"
#include "ffd.h"
#include "fileutils.h"
#include "Generator.h"
#include "Grammar.h"
#include "HydroTile.h"
#include "InstanceManager.h"
#include "Intersections.h"
#include "mapindex.h"
#include "MaterialLibrary.h"
#include "matrix.h"
#include "MatrixAlg.h"
#include "MatrixSSE.h" // AMD
#include "perlin.h"
#include "PhysicsData.h"
#include "PhysicsMaterials.h"
#include "PinkNoise.h"
#include "portability.h"
#include "qef.h"
#include "Quaternion.h"
#include "resource.h"
#include "resource1.h"
#include "ResourceIO.h"
#include "RTree.h"
#include "scene.h"
#include "StampMesh.h"
#include "TileSet.h"
#include "UnionFind.h"
#include "Vector.h"
#include "vectorNative.h"
#include "vfminmax.h"
#include "voxcomp.h"
#include "VoxelFarm.h"
#include "VoxelFarmConfig.h"
#include "VoxelLayer.h"
#include "VoxelSmooth.h"
#include "WhiteNoise.h"
#include "worley.h"

// Demo.GLClient
//#include "glrender.h" // OGL
//#include "glview.h" // OGL
//#include "shaders.h" // OGL
//#include "tga.h" // Targa file processor (OGL)

// VoxelFarmIOLibrary Interfaces
#include "ClientChannel.h"
#include "ExtensionDLL.h"
#include "IOBuffer.h"
#include "ReaderWriterLock.h"
//#include "ReadWriteLock.h" // Seems to be a stub
#include "ServerChannel.h"
#include "VoxelDB.h"
*/

namespace DX
{
    inline void ThrowIfFailed(HRESULT hr)
    {
        if (FAILED(hr))
        {
            // Set a breakpoint on this line to catch DirectX API errors
            throw std::exception();
        }
    }
}