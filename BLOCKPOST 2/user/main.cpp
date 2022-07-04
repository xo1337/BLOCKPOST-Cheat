// Generated C++ file by Il2CppInspector - http://www.djkaty.com - https://github.com/djkaty
// Custom injected code entry point

#include "pch-il2cpp.h"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <iostream>
#include "il2cpp-appdata.h"
#include "helpers.h"
#include <string>
#include <codecvt>
#include <vector>
#include "../il2cpp_resolver_include.hpp"
#include "../Globals.hpp"

#define Log(Arg, ...) printf("[>] " Arg "\n", __VA_ARGS__)

using namespace app;

// Set the name of your log file here
extern HMODULE g_Instance;
extern const LPCWSTR LOG_FILE = L"il2cpp-log.txt";

namespace utils
{
	class Vector2Ex
	{
	public:
		app::Vector2 pos[ 2 ];
	};

    app::Matrix4x4 MultiplyMatrices( app::Matrix4x4& lhs, app::Matrix4x4& rhs )
    {
        app::Matrix4x4 matrixx = app::Matrix4x4( );
        matrixx.m00 = ( ( ( lhs.m00 * rhs.m00 ) + ( lhs.m01 * rhs.m10 ) ) + ( lhs.m02 * rhs.m20 ) ) + ( lhs.m03 * rhs.m30 );
        matrixx.m01 = ( ( ( lhs.m00 * rhs.m01 ) + ( lhs.m01 * rhs.m11 ) ) + ( lhs.m02 * rhs.m21 ) ) + ( lhs.m03 * rhs.m31 );
        matrixx.m02 = ( ( ( lhs.m00 * rhs.m02 ) + ( lhs.m01 * rhs.m12 ) ) + ( lhs.m02 * rhs.m22 ) ) + ( lhs.m03 * rhs.m32 );
        matrixx.m03 = ( ( ( lhs.m00 * rhs.m03 ) + ( lhs.m01 * rhs.m13 ) ) + ( lhs.m02 * rhs.m23 ) ) + ( lhs.m03 * rhs.m33 );
        matrixx.m10 = ( ( ( lhs.m10 * rhs.m00 ) + ( lhs.m11 * rhs.m10 ) ) + ( lhs.m12 * rhs.m20 ) ) + ( lhs.m13 * rhs.m30 );
        matrixx.m11 = ( ( ( lhs.m10 * rhs.m01 ) + ( lhs.m11 * rhs.m11 ) ) + ( lhs.m12 * rhs.m21 ) ) + ( lhs.m13 * rhs.m31 );
        matrixx.m12 = ( ( ( lhs.m10 * rhs.m02 ) + ( lhs.m11 * rhs.m12 ) ) + ( lhs.m12 * rhs.m22 ) ) + ( lhs.m13 * rhs.m32 );
        matrixx.m13 = ( ( ( lhs.m10 * rhs.m03 ) + ( lhs.m11 * rhs.m13 ) ) + ( lhs.m12 * rhs.m23 ) ) + ( lhs.m13 * rhs.m33 );
        matrixx.m20 = ( ( ( lhs.m20 * rhs.m00 ) + ( lhs.m21 * rhs.m10 ) ) + ( lhs.m22 * rhs.m20 ) ) + ( lhs.m23 * rhs.m30 );
        matrixx.m21 = ( ( ( lhs.m20 * rhs.m01 ) + ( lhs.m21 * rhs.m11 ) ) + ( lhs.m22 * rhs.m21 ) ) + ( lhs.m23 * rhs.m31 );
        matrixx.m22 = ( ( ( lhs.m20 * rhs.m02 ) + ( lhs.m21 * rhs.m12 ) ) + ( lhs.m22 * rhs.m22 ) ) + ( lhs.m23 * rhs.m32 );
        matrixx.m23 = ( ( ( lhs.m20 * rhs.m03 ) + ( lhs.m21 * rhs.m13 ) ) + ( lhs.m22 * rhs.m23 ) ) + ( lhs.m23 * rhs.m33 );
        matrixx.m30 = ( ( ( lhs.m30 * rhs.m00 ) + ( lhs.m31 * rhs.m10 ) ) + ( lhs.m32 * rhs.m20 ) ) + ( lhs.m33 * rhs.m30 );
        matrixx.m31 = ( ( ( lhs.m30 * rhs.m01 ) + ( lhs.m31 * rhs.m11 ) ) + ( lhs.m32 * rhs.m21 ) ) + ( lhs.m33 * rhs.m31 );
        matrixx.m32 = ( ( ( lhs.m30 * rhs.m02 ) + ( lhs.m31 * rhs.m12 ) ) + ( lhs.m32 * rhs.m22 ) ) + ( lhs.m33 * rhs.m32 );
        matrixx.m33 = ( ( ( lhs.m30 * rhs.m03 ) + ( lhs.m31 * rhs.m13 ) ) + ( lhs.m32 * rhs.m23 ) ) + ( lhs.m33 * rhs.m33 );
        return matrixx;
    }

    app::Vector3 MultiplyMatrixByVec3( app::Matrix4x4& mat, app::Vector3& vec )
    {
        app::Vector4 vec4 = app::Vector4 { vec.x, vec.y, vec.z, 1.f };
        app::Vector3 result = app::Vector3( );
        result.x = ( ( ( mat.m00 * vec4.x ) + ( mat.m01 * vec4.y ) ) + ( mat.m02 * vec4.z ) ) + ( mat.m03 * vec4.w );
        result.y = ( ( ( mat.m10 * vec4.x ) + ( mat.m11 * vec4.y ) ) + ( mat.m12 * vec4.z ) ) + ( mat.m13 * vec4.w );
        //result.z = (((mat.m20 * vec4.x) + (mat.m21 * vec4.y)) + (mat.m22 * vec4.z)) + (mat.m23 * vec4.w);
        //result.w = (((mat.m30 * vec4.x) + (mat.m31 * vec4.y)) + (mat.m32 * vec4.z)) + (mat.m33 * vec4.w);
        result.z = ( ( ( mat.m30 * vec4.x ) + ( mat.m31 * vec4.y ) ) + ( mat.m32 * vec4.z ) ) + ( mat.m33 * vec4.w );
        return result;
    }


    bool WorldToScreen( Matrix4x4& mvp, Vector3& worldPos, Vector3* screenPos, float halfPixelWidth, float halfPixelHeight )
    {
        bool onScreen = true;
        *screenPos = utils::MultiplyMatrixByVec3( mvp, worldPos );

        if ( screenPos->z < 0.1f )
            onScreen = false;


        screenPos->x = ( screenPos->x / screenPos->z );
        screenPos->y = ( screenPos->y / screenPos->z );

        screenPos->x = ( screenPos->x * halfPixelWidth ) + ( screenPos->x + halfPixelWidth );
        screenPos->y = -( screenPos->y * halfPixelHeight ) + ( screenPos->y + halfPixelHeight );

        return onScreen;
    }   

    std::string utf16_to_utf8( std::u16string u16_string ) {
        std::wstring wide_string( u16_string.begin( ), u16_string.end( ) );
        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> convert;
        return convert.to_bytes( wide_string );
    }

    std::string convert_from_string( app::String* input ) {
        std::u16string u16( reinterpret_cast< const char16_t* >( &input->fields.m_firstChar ) );
        return utf16_to_utf8( u16 );
    }

	// x = x, y = y, z = distance
	app::Vector3 GetDistanceAndAngle( app::Vector3 startPOS, app::Vector3 endPOS )
	{
		float deltaX = endPOS.x - startPOS.x;
		float deltaY = endPOS.y - startPOS.y - 0.1f;
		float deltaZ = endPOS.z - startPOS.z;

		float dist = sqrt(
			pow( ( endPOS.x - startPOS.x ), 2.0 ) +
			pow( ( endPOS.y - startPOS.y ), 2.0 ) +
			pow( ( endPOS.z - startPOS.z ), 2.0 ) );
		if ( dist < 0 )
		{
			dist = dist * -1;
		}

		float xzlength = sqrt( ( deltaX * deltaX ) + ( deltaZ * deltaZ ) );
		float angleX = atan2( deltaY, xzlength ) * ( -57.2957795 );
		float angleY = atan2( deltaX, deltaZ ) * ( 57.2957795 );
		app::Vector3 angle = { angleX,angleY };
		return angle;
	}

	void SetAngles( Vector2 pos )
	{
		app::Controll__StaticFields* controll = ( *app::Controll__TypeInfo )->static_fields;
		controll->rx = pos.y;
		controll->ry = pos.x;
	}

	Vector2Ex GetPlayerLocationData( app::Camera* cam, int i )
	{	
		if ( !cam )
			return { };

		ImVec2 posInScreenTrue;
		ImVec2 posInScreenTrue2;
		Vector2Ex posArray;

		app::PlayerData* enemy = ( *PLH__TypeInfo )->static_fields->player->vector[ i ];

		if ( !enemy )
			return { };

		app::Vector3 posHead = app::Transform_get_position( app::GameObject_get_transform( enemy->fields.goHead, nullptr ), nullptr );
		app::Vector3 WorldPosHead = app::Camera_WorldToScreenPoint( ( *app::Controll__TypeInfo )->static_fields->csCam, posHead, app::Camera_MonoOrStereoscopicEye__Enum::Mono, nullptr );
		app::Vector3 WorldPosLeg = app::Camera_WorldToScreenPoint( ( *app::Controll__TypeInfo )->static_fields->csCam, { posHead.x,posHead.y - 2,posHead.z }, app::Camera_MonoOrStereoscopicEye__Enum::Mono, nullptr );
		
		if ( WorldPosHead.z <= 1.0f )
			return Vector2Ex { };

		if ( WorldPosLeg.z <= 1.0f )
			return Vector2Ex { };

		posInScreenTrue = { WorldPosHead.x,app::Screen_get_height( nullptr ) - WorldPosHead.y };
		posInScreenTrue2 = { WorldPosLeg.x,app::Screen_get_height( nullptr ) - WorldPosLeg.y };
		posArray.pos[ 0 ] = { posInScreenTrue2.x  ,posInScreenTrue2.y };
		posArray.pos[ 1 ] = { posInScreenTrue.x  ,posInScreenTrue.y };
		float width = abs( posInScreenTrue.y - posInScreenTrue2.y ) * 0.3f;
		return { posArray.pos[ 0 ].x + width, posArray.pos[ 0 ].y ,posArray.pos[ 1 ].x - width, posArray.pos[ 1 ].y };
	}
}

void OnDraw( );
void InitImGui( )
{
	ImGui::CreateContext( );

	auto io = ImGui::GetIO( );
	auto& style = ImGui::GetStyle( );

	io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
	io.IniFilename = nullptr;
	io.LogFilename = nullptr;

	style.WindowMinSize = ImVec2( 128, 128 );
	style.WindowTitleAlign = ImVec2( 0.5, 0.5 );
	style.FrameBorderSize = 1;
	style.ChildBorderSize = 1;
	style.WindowBorderSize = 1;
	style.WindowRounding = 0;
	style.FrameRounding = 0;
	style.ChildRounding = 0;
	style.Colors[ ImGuiCol_TitleBg ] = ImColor( 70, 70, 70 );
	style.Colors[ ImGuiCol_TitleBgActive ] = ImColor( 70, 70, 70 );
	style.Colors[ ImGuiCol_TitleBgCollapsed ] = ImColor( 70, 70, 70 );
	style.Colors[ ImGuiCol_WindowBg ] = ImColor( 25, 25, 25, 240 );
	style.Colors[ ImGuiCol_CheckMark ] = ImColor( 70, 70, 70 );
	style.Colors[ ImGuiCol_Border ] = ImColor( 70, 70, 70 );
	style.Colors[ ImGuiCol_Button ] = ImColor( 32, 32, 32 );
	style.Colors[ ImGuiCol_ButtonActive ] = ImColor( 42, 42, 42 );
	style.Colors[ ImGuiCol_ButtonHovered ] = ImColor( 42, 42, 42 );
	style.Colors[ ImGuiCol_ChildBg ] = ImColor( 45, 45, 45 );
	style.Colors[ ImGuiCol_FrameBg ] = ImColor( 32, 32, 32 );
	style.Colors[ ImGuiCol_FrameBgActive ] = ImColor( 42, 42, 42 );
	style.Colors[ ImGuiCol_FrameBgHovered ] = ImColor( 42, 42, 42 );
	style.Colors[ ImGuiCol_SliderGrab ] = ImColor( 255, 255, 255 );
	style.Colors[ ImGuiCol_SliderGrabActive ] = ImColor( 255, 255, 255 );

	io.Fonts->AddFontFromFileTTF( "C:\\Windows\\Fonts\\Tahoma.ttf", 14.0f );

	ImGui_ImplWin32_Init( window );
	ImGui_ImplDX11_Init( pDevice, pContext );
}

__forceinline LRESULT __stdcall WndProc( const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam )
{
	if ( uMsg == WM_KEYUP && wParam == VK_HOME )
		Globals::Open ^= 1;

	if ( Globals::Open )
	{
		ImGui_ImplWin32_WndProcHandler( hWnd, uMsg, wParam, lParam );
		return true;
	}

	return CallWindowProcA( oWndProc, hWnd, uMsg, wParam, lParam );
}

__forceinline HRESULT __stdcall hkPresent( IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags )
{
	static bool SetupHook = false;

	if ( !SetupHook )
	{
		if ( SUCCEEDED( pSwapChain->GetDevice( __uuidof( ID3D11Device ), ( void** )&pDevice ) ) )
		{
			pDevice->GetImmediateContext( &pContext );
			DXGI_SWAP_CHAIN_DESC sd;
			pSwapChain->GetDesc( &sd );

			window = sd.OutputWindow;
			ID3D11Texture2D* pBackBuffer;

			pSwapChain->GetBuffer( 0, __uuidof( ID3D11Texture2D ), ( LPVOID* )&pBackBuffer );
			pDevice->CreateRenderTargetView( pBackBuffer, NULL, &mainRenderTargetView );
			pBackBuffer->Release( );

			oWndProc = ( WNDPROC )SetWindowLongA( window, GWLP_WNDPROC, ( LONG_PTR )WndProc );
			InitImGui( );

			SetupHook = true;
		}

		else
			return oPresent( pSwapChain, SyncInterval, Flags );
	}

	ImGui_ImplDX11_NewFrame( );
	ImGui_ImplWin32_NewFrame( );
	ImGui::NewFrame( );

	ImGui::GetIO( ).MouseDrawCursor = Globals::Open;

	OnDraw( );

	ImGui::Render( );

	pContext->OMSetRenderTargets( 1, &mainRenderTargetView, NULL );
	ImGui_ImplDX11_RenderDrawData( ImGui::GetDrawData( ) );
	return oPresent( pSwapChain, SyncInterval, Flags );
}

void OnDraw( )
{
	static auto Slider = [ & ] ( const char* label, float* value, float min, float max, float width = ImGui::GetContentRegionAvail( ).x )
	{
		ImGui::PushID( label );
		ImGui::PushItemWidth( width );
		ImGui::SliderFloat( _( "##CustomSliderF_" ), value, min, max );
		ImGui::PopItemWidth( );
		ImGui::PopID( );
		ImGui::Spacing( );
	};

	static auto Checkbox = [ & ] ( const char* label, bool* value, bool color_picker = false, float* color_value = 0 )
	{
		ImGui::PushID( label );
		ImGui::Checkbox( label, value );
	
		if ( color_picker )
		{
			static auto flags = ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoTooltip;
			ImGui::SameLine( ImGui::GetContentRegionAvail( ).x - 20 );
			ImGui::ColorEdit4( "##CustomColorPicker_", color_value, flags );
		}

		ImGui::PopID( );
		ImGui::Spacing( );
	};

	if ( Globals::Open )
	{

		ImGui::Begin( _( "D3D11 Hook" ), 0, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize );
		{
			if ( ImGui::Button( _( "Aimbot" ), ImVec2( ImGui::GetContentRegionAvail( ).x / 4, 29 ) ) )
				Globals::Tab = 0;

			ImGui::SameLine( );

			if ( ImGui::Button( _( "Visuals" ), ImVec2( ImGui::GetContentRegionAvail( ).x / 3, 29 ) ) )
				Globals::Tab = 1;

			ImGui::SameLine( );

			if ( ImGui::Button( _( "Other" ), ImVec2( ImGui::GetContentRegionAvail( ).x / 2, 29 ) ) )
				Globals::Tab = 2;

			ImGui::SameLine( );

			if ( ImGui::Button( _( "Settings" ), ImVec2( ImGui::GetContentRegionAvail( ).x / 1, 29 ) ) )
				Globals::Tab = 3;

			ImGui::Spacing( );
			ImGui::Separator( );

			switch ( Globals::Tab )
			{
			case 0: // Aimbot
				Checkbox( _( "Aimbot Enabled" ), &Globals::Aimbot::Enabled );
				Checkbox( _( "Draw FOV" ), &Globals::Aimbot::DrawFOV );
				Checkbox( _( "Draw Filled FOV" ), &Globals::Aimbot::DrawFilledFOV );
				Checkbox( _( "Draw Crosshair" ), &Globals::Aimbot::DrawCrosshair );
				Slider( _( "FOV Size" ), &Globals::Aimbot::DrawFOVSize, 0, 650 );
				break;

			case 1: // Visuals
				Checkbox( _( "ESP Enabled" ), &Globals::Visuals::Enabled );
				Checkbox( _( "Boxes" ), &Globals::Visuals::Boxes, true, Globals::Visuals::CBoxes );
				Checkbox( _( "Filled Boxes" ), &Globals::Visuals::FilledBoxes, true, Globals::Visuals::CFilledBoxes );
				Checkbox( _( "Snaplines" ), &Globals::Visuals::Snaplines, true, Globals::Visuals::CSnaplines );
				Checkbox( _( "Display Info" ), &Globals::Visuals::DisplayInfo, true, Globals::Visuals::CDisplayInfo );
				Checkbox( _( "Display Health" ), &Globals::Visuals::DisplayHealth, true, Globals::Visuals::CDisplayHealth );
				Checkbox( _( "Display Names" ), &Globals::Visuals::DisplayNames, true, Globals::Visuals::CDisplayNames );
				break;

			case 2: // Other
				Checkbox( "Max Ammo", &Globals::Other::MaxAmmo );
				Checkbox( "Max Damage", &Globals::Other::MaxDamage);
				Checkbox( "Max Distance", &Globals::Other::MaxDistance );
				Checkbox( "No Recoil", &Globals::Other::NoRecoil );
				Checkbox( "Rapid fire", &Globals::Other::RapidFire );
				Checkbox( "Pierce Anything", &Globals::Other::PierceAnything );
				break;

			case 3: // Settings
				/*if ( ImGui::Button( _( "Unhook" ) ) )
					Globals::IsClosing = true;*/
				break;
			}
		}
		ImGui::End( );
	}

	// Cheat loop here lol

	{
		const auto draw = ImGui::GetBackgroundDrawList( );
		static const auto size = ImGui::GetIO( ).DisplaySize;
		static const auto center = ImVec2( size.x / 2, size.y / 2 );

		if ( Globals::Aimbot::DrawFOV )
			draw->AddCircle( center, Globals::Aimbot::DrawFOVSize, ImColor( 255, 255, 255 ), 100 );

		if ( Globals::Aimbot::DrawFilledFOV )
			draw->AddCircleFilled( center, Globals::Aimbot::DrawFOVSize, ImColor( 0, 0, 0, 140 ), 100 );

		if ( Globals::Aimbot::DrawCrosshair )
		{
			static const auto whiteColor = ImColor( 255, 255, 255 );
			static const auto mainColor = ImColor( 255, 0, 0 );

			draw->AddLine( center, ImVec2( center.x + 4, center.y + 4 ), whiteColor, 0.7f );
			draw->AddLine( center, ImVec2( center.x + 4, center.y - 4 ), whiteColor, 0.7f );
			draw->AddLine( center, ImVec2( center.x - 4, center.y - 4 ), whiteColor, 0.7f );
			draw->AddLine( center, ImVec2( center.x - 4, center.y + 4 ), whiteColor, 0.7f );
			draw->AddLine( ImVec2( center.x + 4, center.y + 4 ), ImVec2( center.x + 4 + 4, center.y + 4 + 4 ), mainColor, 0.7f );
			draw->AddLine( ImVec2( center.x + 4, center.y - 4 ), ImVec2( center.x + 4 + 4, center.y - 4 - 4 ), mainColor, 0.7f );
			draw->AddLine( ImVec2( center.x - 4, center.y - 4 ), ImVec2( center.x - 4 - 4, center.y - 4 - 4 ), mainColor, 0.7f );
			draw->AddLine( ImVec2( center.x - 4, center.y + 4 ), ImVec2( center.x - 4 - 4, center.y + 4 + 4 ), mainColor, 0.7f );
		}

		auto cam = ( *app::Controll__TypeInfo )->static_fields->csCam;

		if ( cam )
		{
			Vector3 camWorldPos = Vector3 { 0.f, 0.f, 0.f };

			int32_t pixelWidth = size.x;//Camera_get_pixelWidth( cam, nullptr );
			int32_t pixelHeight = size.y;//Camera_get_pixelHeight( cam, nullptr );

			Matrix4x4 worldToCameraMat = Camera_get_worldToCameraMatrix( cam, nullptr );
			Matrix4x4 projMat = Camera_get_projectionMatrix( cam, nullptr );

			Matrix4x4 mvp = utils::MultiplyMatrices( projMat, worldToCameraMat );

			PlayerData__Array* playerData = ( *PLH__TypeInfo )->static_fields->player;

			if ( playerData )
			{
				int actorAim;
				for ( unsigned int i = 0; i < playerData->max_length; i++ )
				{
					auto player = playerData->vector[ i ];

					if ( !player )
						continue;

					if ( player->fields.currPos.x == 0 )
						continue;

					// Team check
					if ( player->fields.team == ( *app::Controll__TypeInfo )->static_fields->pl->fields.team )
						continue;

					app::Vector3 out = { 0,0,0 };
					app::Vector3 current = player->fields.Pos;

					if ( utils::WorldToScreen( mvp, current, &out, pixelWidth / 2, pixelHeight / 2 ) )
					{
						int health = player->fields.health;
						auto name = utils::convert_from_string( player->fields.name );

						if ( Globals::Aimbot::Enabled && GetAsyncKeyState( VK_RBUTTON ) & 0x8000 )
						{
							class myCamera {
							public:
								char pad[ 0x3b4 ];
								Vector3 campos;
							};

							class cscamera {
							public:
								char pad[ 8 ];
								myCamera* camira;
							};

							//float bestDistance = 0;
							auto angles = utils::GetDistanceAndAngle( ( ( cscamera* )( ( *app::Controll__TypeInfo )->static_fields->csCam ) )->camira->campos, current );

							//if ( angles.z <= Globals::Aimbot::DrawFOVSize )
							//{
							//	bestDistance = angles.z;

							float x = ( *app::Controll__TypeInfo )->static_fields->rx;
							float y = ( *app::Controll__TypeInfo )->static_fields->ry;
							//	float normalDistance = angles.x;
							//	float realDistance = y - normalDistance;

							if ( angles.y < 0 ) angles.y = 360 + y;
							if ( angles.x < 0 ) angles.x = 360 + x;

							// Not in FOV
							//if ( realDistance < -Globals::Aimbot::DrawFOVSize || realDistance > Globals::Aimbot::DrawFOVSize ) continue;
							if ((out.x < (center.x + Globals::Aimbot::DrawFOVSize)) and (out.x > (center.x - Globals::Aimbot::DrawFOVSize))
							and (out.y < (center.y + Globals::Aimbot::DrawFOVSize)) and (out.y > (center.y - Globals::Aimbot::DrawFOVSize)) || i == actorAim)
							{
								actorAim = i;
								if (GetAsyncKeyState(VK_RBUTTON) & 0x8000) {
									utils::SetAngles({ angles.x, angles.y });
								}
							}

							//}
						}

						if ( Globals::Visuals::Boxes ) {
							auto data = utils::GetPlayerLocationData( cam, i );
							draw->AddRect( { data.pos[ 0 ].x, data.pos[ 0 ].y + 3 }, ImVec2 { data.pos[ 1 ].x, data.pos[ 1 ].y - 3 }, IM_COLOR( Globals::Visuals::CBoxes ), 0 );
						}

						if ( Globals::Visuals::Corners ) {

						}

						if ( Globals::Visuals::FilledBoxes ) {
							auto data = utils::GetPlayerLocationData( cam, i );
							draw->AddRectFilled( { data.pos[ 0 ].x, data.pos[ 0 ].y + 3}, ImVec2 { data.pos[ 1 ].x, data.pos[ 1 ].y - 3}, ImColor( 0, 0, 0, 130 ) );
						}

						if ( Globals::Visuals::Snaplines ) {
							draw->AddLine( center, ImVec2( out.x, out.y ), IM_COLOR( Globals::Visuals::CSnaplines ) );
						}

						if ( Globals::Visuals::DisplayInfo ) {
							char buf[ 156 ];
							sprintf_s( buf, "[%s] | %i", name.c_str( ), health );
							draw->AddText( ImVec2( out.x, out.y ), IM_COLOR( Globals::Visuals::CDisplayInfo ), buf );
						}

						if ( Globals::Visuals::DisplayHealth ) {
							draw->AddText( ImVec2( out.x, out.y ), IM_COLOR( Globals::Visuals::CDisplayHealth ), std::to_string( health ).c_str( ) );
						}

						if ( Globals::Visuals::DisplayNames ) {
							draw->AddText( ImVec2( out.x, out.y ), ImColor( 255, 0, 0 ), utils::convert_from_string( player->fields.name ).c_str( ) );
						}
					}
				}
			}

			if ( Globals::Other::Enabled )
			{
				auto local = ( *app::Controll__TypeInfo )->static_fields->pl;
				if ( local )
				{
					auto weapons = local->fields.weapon->fields._items;
					for ( int i = 0; i < weapons->max_length; i++ )
					{
						auto weapon = weapons->vector[ i ];
						if ( !weapon )
							continue;

						if ( Globals::Other::MaxAmmo )
						{
							unsigned char bytes[] = { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 };
							auto addr = reinterpret_cast< void* >( weapon->fields.wi->fields.ammo );
							memcpy( ( void* )addr, &bytes, sizeof( bytes ) );
						}

						if ( Globals::Other::MaxDamage )
							weapon->fields.wi->fields.damage = 999999;

						if ( Globals::Other::MaxDistance )
							weapon->fields.wi->fields.distance = 999999;

						if ( Globals::Other::NoRecoil )
							weapon->fields.wi->fields.recoil = 0;

						if ( Globals::Other::RapidFire )
							weapon->fields.wi->fields.firerate = 4;

						if ( Globals::Other::PierceAnything )
							weapon->fields.wi->fields.piercing = 1;
					}			
				}
			}
		}
	}
}

int MainThread( )
{

#if CONSOLE_LOGGING
	AllocConsole( );
	freopen_s( ( FILE** )stdout, "CONOUT$", "w", stdout );
#endif

	IL2CPPInitialize( );

	Log( "Injected at: %s", __TIME__ );
	Log( "Module Instance: 0x%p", reinterpret_cast< void* >( Globals::DllInstance ) );

	static bool Done = false;

	while ( !Done )
	{
		if ( kiero::init( kiero::RenderType::D3D11 ) == kiero::Status::Success )
		{
			kiero::bind( 8, ( void** )&oPresent, hkPresent );
			Done = true;
		}
	}

	while ( true )
	{
		if ( ( GetAsyncKeyState( VK_END ) & 1 ) || Globals::IsClosing )
			break;

		Sleep( 1000 );
	}

	Log( "Unhooked at: %s", __TIME__ );

	Globals::IsClosing = false;
	Globals::Open = false;

	kiero::unbind( 8 );
	kiero::shutdown( );

	FreeLibrary( ( HMODULE )Globals::DllInstance );
	return TRUE;
}


void Run()
{
    // Initialize thread data - DO NOT REMOVE
    il2cpp_thread_attach(il2cpp_domain_get());
    il2cppi_new_console( );

    Log( "EntryPoint." );

    if ( IL2CPPInitialize( ) )
    {
        Log( "IL2CPP Initialized!" );
    }

	MainThread( );

    Log( "Exit" );
    FreeLibraryAndExitThread( g_Instance, 0 );
}
