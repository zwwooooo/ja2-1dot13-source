	#include "WordWrap.h"
	#include "sgp.h"
	#include "Encrypted File.h"
	#include "IMP Text System.h"
	#include "CharProfile.h"
	#include "laptop.h"
	#include "IMP Personality Quiz.h"
	#include "IMP Personality Finish.h"
	#include "IMP Attribute Selection.h"
	#include "IMP MainPage.h"
	// added by SANDRO
	#include "IMP Confirm.h"
	#include "GameSettings.h"
	#include "Text.h"
	#include "_Ja25Englishtext.h"
#ifdef JA2UB
	#include "laptop.h"
	#include "email.h"
	#include "Utilities.h"
	#include "WCheck.h"
	#include "Debug.h"
	#include "WordWrap.h"
	#include "Encrypted File.h"
	#include "cursors.h"
	#include "soldier profile.h"
	#include "IMP Compile Character.h"
	#include "IMP Voices.h"
	#include "IMP Portraits.h"
	#include "Game Clock.h"
	#include "environment.h"
	#include "AimMembers.h"
	#include "Random.h"
	#include "Text.h"
	#include "LaptopSave.h"
	#include "finances.h"
	#include "PostalService.h"
	#include "faces.h"
	#include "GameSettings.h"
#endif

#include <language.hpp>

#define IMP_SEEK_AMOUNT 5 * 80 * 2

#define	IMP_LEFT_IDENT_TEXT_X						iScreenWidthOffset + 116
#define	IMP_RIGHT_IDENT_TEXT_X						iScreenWidthOffset + 509
#define	IMP_IDENT_WIDTH									96

BOOLEAN fInitialized = FALSE;


INT32 iIMPTextRecordLengths[ 300 ];


// the length of persona questions
INT32 iIMPQuestionLengths[25]=
{
	7,5,5,6,5,6,5,5,5,5,6,9,5,5,5,5,5,5,5,5,7,10,6,5,5,
};


// function headers
void PrintIMPPersonalityQuizQuestionAndAnsers( void );
void OffSetQuestionForFemaleSpecificQuestions( INT32 *iCurrentOffset );


#define QTN_FIRST_COLUMN_X					iScreenWidthOffset + 80
#define QTN_SECOND_COLUMN_X					iScreenWidthOffset + 320

#ifdef JA2UB
#define		IMPTEXT_EDT_FILE_JA25			"BINARYDATA\\IMPText25.edt"
#define		IMPTEXT_EDT_FILE_JA2		"BINARYDATA\\IMPText.edt"
#endif

void LoadAndDisplayIMPText( INT16 sStartX, INT16 sStartY, INT16 sLineLength, INT16 sIMPTextRecordNumber, UINT32 uiFont, UINT8 ubColor, BOOLEAN fShadow, UINT32 uiFlags)
{
	// this procedure will load and display to the screen starting at postion X, Y relative to the start of the laptop screen
	// it will access record sIMPTextRecordNumber and go until all records following it but before the next IMP record are displayed in font uiFont
	CHAR16 sString[ 1024 ];

	if( fShadow == FALSE )
	{
		// don't want shadow, remove it
		SetFontShadow( NO_SHADOW );
	}

	// load the string
#ifdef JA2UB
	if (FileExists(IMPTEXT_EDT_FILE_JA25))
	{
	LoadEncryptedDataFromFile(IMPTEXT_EDT_FILE_JA25, sString, ( UINT32 ) ( ( sIMPTextRecordNumber ) * IMP_SEEK_AMOUNT ), IMP_SEEK_AMOUNT);
	}
	else
	{
	LoadEncryptedDataFromFile(IMPTEXT_EDT_FILE_JA2, sString, ( UINT32 ) ( ( sIMPTextRecordNumber ) * IMP_SEEK_AMOUNT ), IMP_SEEK_AMOUNT);	
	}
#else
	LoadEncryptedDataFromFile("BINARYDATA\\IMPText.EDT", sString, ( UINT32 ) ( ( sIMPTextRecordNumber ) * IMP_SEEK_AMOUNT ), IMP_SEEK_AMOUNT);
#endif

	// null put last char
	sString[ wcslen( sString) ] = 0;


	if( uiFlags == 0 )
	{
		uiFlags = LEFT_JUSTIFIED;
	}

	DisplayWrappedString( sStartX, ( INT16 )( sStartY	), sLineLength, 2, uiFont, ubColor, sString, FONT_BLACK,FALSE, uiFlags);


	// reset shadow
	SetFontShadow( DEFAULT_SHADOW );


}


void InitializeImpRecordLengthList( void )
{

	// this procedure will setup the IMP records length list with the appropriate values


	return;

}


void PrintImpText( void )
{
	INT16 sWidth = LAPTOP_TEXT_WIDTH;

	// looks at current page and prints text needed
	switch( iCurrentImpPage )
	{
		case ( IMP_HOME_PAGE ):
		// the imp homepage
	 LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X - 111, iScreenHeightOffset + LAPTOP_SCREEN_WEB_DELTA_Y + 43, sWidth, IMP_HOME_1, FONT14ARIAL, FONT_WHITE, TRUE, CENTER_JUSTIFIED );
	 LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X - 111, iScreenHeightOffset + LAPTOP_SCREEN_WEB_DELTA_Y +60, sWidth, IMP_HOME_2, FONT10ARIAL, FONT_WHITE, TRUE, CENTER_JUSTIFIED );
	 LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X - 111, iScreenHeightOffset + LAPTOP_SCREEN_WEB_DELTA_Y +208, sWidth,IMP_HOME_3, FONT14ARIAL, FONT_WHITE, TRUE, CENTER_JUSTIFIED );
	 LoadAndDisplayIMPText( IMP_LEFT_IDENT_TEXT_X, iScreenHeightOffset + LAPTOP_SCREEN_WEB_DELTA_Y +99, IMP_IDENT_WIDTH,IMP_HOME_7, FONT10ARIAL, 142, TRUE, CENTER_JUSTIFIED);
	 LoadAndDisplayIMPText( IMP_RIGHT_IDENT_TEXT_X, iScreenHeightOffset + LAPTOP_SCREEN_WEB_DELTA_Y +99, IMP_IDENT_WIDTH,IMP_HOME_8, FONT10ARIAL, 142, TRUE, CENTER_JUSTIFIED);
	 LoadAndDisplayIMPText( iScreenWidthOffset + 258, iScreenHeightOffset + LAPTOP_SCREEN_WEB_DELTA_Y +362, ( 640 ),IMP_HOME_5, FONT14ARIAL, FONT_BLACK, FALSE, 0);
	 LoadAndDisplayIMPText( IMP_LEFT_IDENT_TEXT_X, iScreenHeightOffset + LAPTOP_SCREEN_WEB_DELTA_Y +188, IMP_IDENT_WIDTH,IMP_HOME_9, FONT10ARIAL, 142, TRUE, RIGHT_JUSTIFIED);
	 LoadAndDisplayIMPText( IMP_RIGHT_IDENT_TEXT_X, iScreenHeightOffset + LAPTOP_SCREEN_WEB_DELTA_Y +188, IMP_IDENT_WIDTH,IMP_HOME_10, FONT10ARIAL, 142, TRUE, RIGHT_JUSTIFIED);
	 LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X - 111, iScreenHeightOffset + LAPTOP_SCREEN_WEB_DELTA_Y +402, sWidth, IMP_HOME_6, FONT12ARIAL, FONT_WHITE, TRUE, CENTER_JUSTIFIED);

		break;
		case ( IMP_ABOUT_US ):
		LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + 17, LAPTOP_SCREEN_WEB_UL_Y + 137, ( 640 ),IMP_ABOUT_US_1, FONT12ARIAL, FONT_WHITE, TRUE, 0);
		LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + 25, LAPTOP_SCREEN_WEB_UL_Y + 154, ( 337 - 124 ), IMP_ABOUT_US_2, FONT10ARIAL, 142, TRUE, 0);
		LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + 25, LAPTOP_SCREEN_WEB_UL_Y + 235, ( 337 - 124 ), IMP_ABOUT_US_3, FONT10ARIAL, 142, TRUE, 0);
			LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + 17, LAPTOP_SCREEN_WEB_UL_Y + 260, ( 640 ), IMP_ABOUT_US_10, FONT12ARIAL, FONT_WHITE, TRUE, 0);
		LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + 25, LAPTOP_SCREEN_WEB_UL_Y + 280, ( 337 - 124 ), IMP_ABOUT_US_4, FONT10ARIAL, 142, TRUE, 0);
		LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + 267, LAPTOP_SCREEN_WEB_UL_Y + 137, ( 640 ), IMP_ABOUT_US_11, FONT12ARIAL, FONT_WHITE, TRUE, 0);
		LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + 275, LAPTOP_SCREEN_WEB_UL_Y + 154, ( 337 - 129 ), IMP_ABOUT_US_5, FONT10ARIAL, 142, TRUE, 0);
		LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + 267, LAPTOP_SCREEN_WEB_UL_Y + 227, ( 640 ), IMP_ABOUT_US_8, FONT12ARIAL, FONT_WHITE, TRUE, 0);
		LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + 275, LAPTOP_SCREEN_WEB_UL_Y + 247, ( 337 - 129	), IMP_ABOUT_US_6, FONT10ARIAL, 142, TRUE, 0);
		LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + 267, LAPTOP_SCREEN_WEB_UL_Y + 277, ( 640 ), IMP_ABOUT_US_9, FONT12ARIAL, FONT_WHITE, TRUE, 0);
		LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + 275, LAPTOP_SCREEN_WEB_UL_Y + 297, ( 337 - 129	), IMP_ABOUT_US_7, FONT10ARIAL, 142, TRUE, 0);

		break;
		case ( IMP_MAIN_PAGE ):
		// title
			
			LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X - 111, LAPTOP_TITLE_Y, sWidth, IMP_MAIN_1, FONT14ARIAL, FONT_WHITE, TRUE, CENTER_JUSTIFIED);

			// set up for IMP text for title box area
			switch( iCurrentProfileMode )
			{
			case( IMP__REGISTRY ):
				LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + 173, LAPTOP_SCREEN_WEB_UL_Y + 91, ( 329 - 173	), IMP_MAIN_2, FONT10ARIAL, 142, TRUE, 0);
				break;
				case( IMP__PORTRAIT ):
					IanDisplayWrappedString( LAPTOP_SCREEN_UL_X + 173, LAPTOP_SCREEN_WEB_UL_Y + 91, ( 329 - 173	), 2, FONT10ARIAL, 142, pExtraIMPStrings[ 2 ],0,FALSE,0);
				break;
				case( IMP__VOICE ):
					IanDisplayWrappedString( LAPTOP_SCREEN_UL_X + 173, LAPTOP_SCREEN_WEB_UL_Y + 91, ( 329 - 173	), 2, FONT10ARIAL, 142, pExtraIMPStrings[ 3 ],0,FALSE,0);
				break;
				case( IMP__PERSONALITY ):
					IanDisplayWrappedString( LAPTOP_SCREEN_UL_X + 173, LAPTOP_SCREEN_WEB_UL_Y + 91, ( 329 - 173	), 2, FONT10ARIAL, 142, pExtraIMPStrings[ 0 ],0,FALSE,0);
				break;
				case( IMP__ATTRIBUTES ):
					IanDisplayWrappedString( LAPTOP_SCREEN_UL_X + 173, LAPTOP_SCREEN_WEB_UL_Y + 91, ( 329 - 173	), 2, FONT10ARIAL, 142, pExtraIMPStrings[ 1 ],0,FALSE,0);
				break;

			}

		break;
		case ( IMP_BEGIN ):

			// title
			LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X - 111, LAPTOP_TITLE_Y, sWidth, IMP_BEGIN_1, FONT14ARIAL, FONT_WHITE, TRUE, CENTER_JUSTIFIED );
		LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + 105, LAPTOP_SCREEN_WEB_UL_Y + 67, ( 390 - 105	), IMP_BEGIN_2, FONT10ARIAL, 142, TRUE, CENTER_JUSTIFIED);

			// fullname
			LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + 81, LAPTOP_SCREEN_WEB_UL_Y + 139, ( 640	), IMP_BEGIN_3, FONT14ARIAL, FONT_BLACK, FALSE, 0);

			// nick name
			LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + 81, LAPTOP_SCREEN_WEB_UL_Y + 199, ( 640	), IMP_BEGIN_4, FONT14ARIAL, FONT_BLACK, FALSE, 0);

			// gender
			LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + 81, LAPTOP_SCREEN_WEB_UL_Y + 259, ( 640	), IMP_BEGIN_6, FONT14ARIAL, FONT_BLACK, FALSE, 0);

//inshy (18.01.2009): fix position for russian text
	if( g_lang == i18n::Lang::ru ) {
			// male
			LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + 225, LAPTOP_SCREEN_WEB_UL_Y + 259, ( 640	), IMP_BEGIN_10, FONT14ARIAL, FONT_BLACK, FALSE, 0);
			// female
			LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + 335, LAPTOP_SCREEN_WEB_UL_Y + 259, ( 640	), IMP_BEGIN_11, FONT14ARIAL, FONT_BLACK, FALSE, 0);
	} else {
			// male
			LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + 240, LAPTOP_SCREEN_WEB_UL_Y + 259, ( 640	), IMP_BEGIN_10, FONT14ARIAL, FONT_BLACK, FALSE, 0);

			// female
			LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + 360, LAPTOP_SCREEN_WEB_UL_Y + 259, ( 640	), IMP_BEGIN_11, FONT14ARIAL, FONT_BLACK, FALSE, 0);
	}

		break;
		case ( IMP_PERSONALITY ):
		// SANDRO - I HAVE CHANGED THESE TO BE ABLE TO EDIT THE TEXTS BEFORE SKILL TRAITS
		// EVEN IF IT IS A LITTLE STUPID WAY, I HAVEN'T FOUND A DIFFERENT WAY
		//LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + 130, LAPTOP_SCREEN_WEB_UL_Y + 60, ( 456 - 200	), IMP_PERS_1, FONT12ARIAL, FONT_WHITE, TRUE, CENTER_JUSTIFIED);
		//LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + 130, LAPTOP_SCREEN_WEB_UL_Y + 130, ( 456 - 200	), IMP_PERS_2, FONT12ARIAL, FONT_WHITE, TRUE, CENTER_JUSTIFIED);
			if ( gGameOptions.fNewTraitSystem )
			{
				CHAR16 sString[400];
				swprintf( sString, pSkillTraitBeginIMPStrings[ 2 ], gSkillTraitValues.ubNumberOfMajorTraitsAllowedForIMP );
				DisplayWrappedString( LAPTOP_SCREEN_UL_X + 130, LAPTOP_SCREEN_WEB_UL_Y + 57,  ( 456 - 200 ), 2, FONT12ARIAL, FONT_WHITE, sString,FONT_BLACK,FALSE,CENTER_JUSTIFIED);
				swprintf( sString, pSkillTraitBeginIMPStrings[ 3 ], gSkillTraitValues.ubMaxNumberOfTraitsForIMP, gSkillTraitValues.ubMaxNumberOfTraitsForIMP, gSkillTraitValues.ubMaxNumberOfTraitsForIMP -2 );
				DisplayWrappedString( LAPTOP_SCREEN_UL_X + 130, LAPTOP_SCREEN_WEB_UL_Y + 155,  ( 456 - 200 ), 2, FONT12ARIAL, FONT_WHITE, sString,FONT_BLACK,FALSE,CENTER_JUSTIFIED);
			}
			else
			{
				DisplayWrappedString( LAPTOP_SCREEN_UL_X + 130, LAPTOP_SCREEN_WEB_UL_Y + 57,  ( 456 - 200 ), 2, FONT12ARIAL, FONT_WHITE, pSkillTraitBeginIMPStrings[ 0 ],FONT_BLACK,FALSE,CENTER_JUSTIFIED);
				DisplayWrappedString( LAPTOP_SCREEN_UL_X + 130, LAPTOP_SCREEN_WEB_UL_Y + 140,  ( 456 - 200 ), 2, FONT12ARIAL, FONT_WHITE, pSkillTraitBeginIMPStrings[ 1 ],FONT_BLACK,FALSE,CENTER_JUSTIFIED);
			}
		LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X - 111, LAPTOP_TITLE_Y, sWidth, IMP_PERS_6, FONT14ARIAL, FONT_WHITE, TRUE, CENTER_JUSTIFIED );


		break;
		case ( IMP_PERSONALITY_QUIZ ):
//		LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X, LAPTOP_SCREEN_WEB_UL_Y + 5, sWidth, IMP_PERS_6, FONT14ARIAL, FONT_WHITE, TRUE, CENTER_JUSTIFIED );
//		LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + 293, LAPTOP_SCREEN_WEB_UL_Y + 370, ( 456 - 200	), IMP_PERS_11, FONT12ARIAL, FONT_WHITE, TRUE, 0);
//		LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + 363, LAPTOP_SCREEN_WEB_UL_Y + 370, ( 456 - 200	), IMP_PERS_12, FONT12ARIAL, FONT_WHITE, TRUE, 0);

			// print the question and suitable answers
//			PrintIMPPersonalityQuizQuestionAndAnsers( );

		break;
		case ( IMP_PERSONALITY_FINISH ):
		LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X, LAPTOP_TITLE_Y, sWidth, IMP_PERS_6, FONT14ARIAL, FONT_WHITE, TRUE, CENTER_JUSTIFIED);
			switch( bPersonalityEndState )
			{
			case( 0 ):
			LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + 125, LAPTOP_SCREEN_WEB_UL_Y + 100, ( 356 - 100 ), IMP_PERS_F1, FONT14ARIAL, FONT_WHITE, TRUE, CENTER_JUSTIFIED);
		 break;
			case( 1 ):
			LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + 125, LAPTOP_SCREEN_WEB_UL_Y + 100, ( 356 - 100	), IMP_PERS_F4, FONT14ARIAL, FONT_WHITE, TRUE, CENTER_JUSTIFIED);
			break;
			case( 2 ):
			LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + 125, LAPTOP_SCREEN_WEB_UL_Y + 100, ( 356 - 100	), IMP_PERS_F5, FONT14ARIAL, FONT_WHITE, TRUE, CENTER_JUSTIFIED);
			break;
			}
		break;
		case( IMP_ATTRIBUTE_ENTRANCE ):
			if ( gGameOptions.fNewTraitSystem )
			{
				CHAR16 sMinAttr[400];
				swprintf( sMinAttr, sgAttributeSelectionText[ 4 ], gGameExternalOptions.iMinAttribute );
				DisplayWrappedString( LAPTOP_SCREEN_UL_X + 122, LAPTOP_SCREEN_WEB_UL_Y + 57,  ( 466 - 190 ), 2, FONT12ARIAL, FONT_WHITE, sMinAttr,FONT_BLACK,FALSE,CENTER_JUSTIFIED);
				DisplayWrappedString( LAPTOP_SCREEN_UL_X + 122, LAPTOP_SCREEN_WEB_UL_Y + 116,  ( 466 - 190 ), 2, FONT12ARIAL, FONT_WHITE, sgAttributeSelectionText[ 5 ],FONT_BLACK,FALSE,CENTER_JUSTIFIED);
				DisplayWrappedString( LAPTOP_SCREEN_UL_X + 122, LAPTOP_SCREEN_WEB_UL_Y + 163,  ( 466 - 190 ), 2, FONT12ARIAL, FONT_WHITE, sgAttributeSelectionText[ 6 ],FONT_BLACK,FALSE,CENTER_JUSTIFIED);
			}
			else
			{
				LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X - 111, LAPTOP_TITLE_Y, sWidth, IMP_ATTRIB_1 - 1, FONT14ARIAL, FONT_WHITE, TRUE, CENTER_JUSTIFIED);
				LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + 110, LAPTOP_SCREEN_WEB_UL_Y + 50, ( 300 ), IMP_ATTRIB_5, FONT12ARIAL, FONT_WHITE, TRUE, CENTER_JUSTIFIED);
				LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + 110, LAPTOP_SCREEN_WEB_UL_Y + 130, ( 300 ), IMP_ATTRIB_6, FONT12ARIAL, FONT_WHITE, TRUE, CENTER_JUSTIFIED);
				LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + 110, LAPTOP_SCREEN_WEB_UL_Y + 200, ( 300 ), IMP_ATTRIB_7, FONT12ARIAL, FONT_WHITE, TRUE, CENTER_JUSTIFIED);
			}
		break;
	case( IMP_ATTRIBUTE_PAGE ):
		LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X - 111, LAPTOP_TITLE_Y, sWidth, IMP_ATTRIB_1 - 1, FONT14ARIAL, FONT_WHITE, TRUE, CENTER_JUSTIFIED);

			// Moved this to "IMP Attribute Selection.cpp" - SANDRO
			// don't blit bonus if reviewing
			/*if( fReviewStats != TRUE )
			{
			LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + 355, LAPTOP_SCREEN_WEB_UL_Y + 51, ( 640	), IMP_ATTRIB_SA_2 - 1, FONT12ARIAL, FONT_WHITE, TRUE, 0);
		LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + 56, LAPTOP_SCREEN_WEB_UL_Y + 33, ( 240 ), IMP_ATTRIB_SA_15, FONT10ARIAL, FONT_WHITE, TRUE, 0);
			}
			else
			{
				LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + 56, LAPTOP_SCREEN_WEB_UL_Y + 33, ( 240 ), IMP_ATTRIB_SA_18, FONT10ARIAL, FONT_WHITE, TRUE, 0);
			}*/
			// stats
		// health
			LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + 60, LAPTOP_SCREEN_WEB_UL_Y + SKILL_SLIDE_START_Y + 0 * SKILL_SLIDE_HEIGHT, ( 100	), IMP_ATTRIB_SA_6 - 1, FONT12ARIAL, FONT_WHITE, TRUE, RIGHT_JUSTIFIED);
		// dex
			LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + 60, LAPTOP_SCREEN_WEB_UL_Y + SKILL_SLIDE_START_Y + 1 * SKILL_SLIDE_HEIGHT, ( 100	), IMP_ATTRIB_SA_8 - 1, FONT12ARIAL, FONT_WHITE, TRUE, RIGHT_JUSTIFIED);
		// agili
			LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + 60, LAPTOP_SCREEN_WEB_UL_Y + SKILL_SLIDE_START_Y + 2 * SKILL_SLIDE_HEIGHT, ( 100	), IMP_ATTRIB_SA_7 - 1, FONT12ARIAL, FONT_WHITE, TRUE, RIGHT_JUSTIFIED);
		// str
			LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + 60, LAPTOP_SCREEN_WEB_UL_Y + SKILL_SLIDE_START_Y + 3 * SKILL_SLIDE_HEIGHT, ( 100	), IMP_ATTRIB_SA_9 - 1, FONT12ARIAL, FONT_WHITE, TRUE, RIGHT_JUSTIFIED);
		// wisdom
			LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + 60, LAPTOP_SCREEN_WEB_UL_Y + SKILL_SLIDE_START_Y + 4 * SKILL_SLIDE_HEIGHT, ( 100	), IMP_ATTRIB_SA_11 - 1, FONT12ARIAL, FONT_WHITE, TRUE, RIGHT_JUSTIFIED);
		// lead
			LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + 60, LAPTOP_SCREEN_WEB_UL_Y + SKILL_SLIDE_START_Y + 5 * SKILL_SLIDE_HEIGHT, ( 100	), IMP_ATTRIB_SA_10 - 1, FONT12ARIAL, FONT_WHITE, TRUE, RIGHT_JUSTIFIED);
		// marks
			LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + 60, LAPTOP_SCREEN_WEB_UL_Y + SKILL_SLIDE_START_Y + 6 * SKILL_SLIDE_HEIGHT, ( 100	), IMP_ATTRIB_SA_12 - 1, FONT12ARIAL, FONT_WHITE, TRUE, RIGHT_JUSTIFIED);
		// med
			LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + 60, LAPTOP_SCREEN_WEB_UL_Y + SKILL_SLIDE_START_Y + 7 * SKILL_SLIDE_HEIGHT, ( 100	), IMP_ATTRIB_SA_14 - 1, FONT12ARIAL, FONT_WHITE, TRUE, RIGHT_JUSTIFIED);
		// expl
			LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + 60, LAPTOP_SCREEN_WEB_UL_Y + SKILL_SLIDE_START_Y + 8 * SKILL_SLIDE_HEIGHT, ( 100	), IMP_ATTRIB_SA_15 - 1, FONT12ARIAL, FONT_WHITE, TRUE, RIGHT_JUSTIFIED);
		// mech
			LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + 60, LAPTOP_SCREEN_WEB_UL_Y + SKILL_SLIDE_START_Y + 9 * SKILL_SLIDE_HEIGHT, ( 100	), IMP_ATTRIB_SA_13 - 1, FONT12ARIAL, FONT_WHITE, TRUE, RIGHT_JUSTIFIED);

		// should we display zero warning or nowmal ' come on herc..' text



		break;
	case( IMP_ATTRIBUTE_FINISH ):
			LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X - 111, LAPTOP_TITLE_Y, sWidth, IMP_ATTRIB_1 - 1, FONT14ARIAL, FONT_WHITE, TRUE, CENTER_JUSTIFIED);

			LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + 125, LAPTOP_SCREEN_WEB_UL_Y + 100, ( 356 - 100 ), IMP_AF_2 - 1, FONT14ARIAL, FONT_WHITE, TRUE, CENTER_JUSTIFIED);

		break;
		case ( IMP_PORTRAIT ):
		LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X - 111, LAPTOP_TITLE_Y, sWidth, IMP_POR_1 - 1, FONT14ARIAL, FONT_WHITE, TRUE, CENTER_JUSTIFIED);
			LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + 135, LAPTOP_SCREEN_WEB_UL_Y + 68, ( 240	), IMP_POR_2 - 1, FONT10ARIAL, 142, TRUE, 0);

		break;
		case ( IMP_VOICE ):
		LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X - 111, LAPTOP_TITLE_Y, sWidth, IMP_VOC_1 - 1, FONT14ARIAL, FONT_WHITE, TRUE, CENTER_JUSTIFIED);
			LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + 135, LAPTOP_SCREEN_WEB_UL_Y + 70, ( 240	), IMP_VOC_2 - 1, FONT10ARIAL, 142, TRUE, 0);
		break;
		case ( IMP_FINISH ):
		//LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + 160, LAPTOP_TITLE_Y, ( 640	), IMP_FIN_1 - 1, FONT14ARIAL, FONT_WHITE, TRUE, 0);
			LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + 150, LAPTOP_SCREEN_WEB_UL_Y + 55, ( 200	), IMP_FIN_2 - 1, FONT12ARIAL, FONT_WHITE, TRUE, 0);
		break;
		case( IMP_CONFIRM ):
			LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X - 111, LAPTOP_TITLE_Y, sWidth, IMP_CON_1 , FONT14ARIAL, FONT_WHITE, TRUE, CENTER_JUSTIFIED);
			LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + 160, LAPTOP_SCREEN_WEB_UL_Y + 60, ( 200	), IMP_CON_2 , FONT12ARIAL, FONT_WHITE, TRUE, 0);
			//LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + 160, LAPTOP_SCREEN_WEB_UL_Y + 145, ( 200	), IMP_CON_3 , FONT12ARIAL, FONT_WHITE, TRUE, 0);
			// SANDRO - changed to show exact cost of profile
			CHAR16 chPayCost[1000];
			swprintf( chPayCost, gzIMPProfileCostText[ 0 ], GetProfileCost(TRUE, FALSE) );
			DisplayWrappedString( LAPTOP_SCREEN_UL_X + 160, LAPTOP_SCREEN_WEB_UL_Y + 145,  ( 200 ), 2, FONT12ARIAL, FONT_WHITE, chPayCost,FONT_BLACK,FALSE,LEFT_JUSTIFIED);

		break;
	}
}

void PrintImpTextPostButtonRender( void )
{
	// prints any text after IMP buttons have been rendered
	switch( iCurrentImpPage )
	{
		case ( IMP_HOME_PAGE ):
			// about us button
	break;
	}
}


void PrintIMPPersonalityQuizQuestionAndAnsers( void )
{

	INT32 iCounter = 0;
	INT32 iOffset = 0;

	if( giCurrentPersonalityQuizQuestion < 0 )
	{
		return;
	}

	// how far into text is the question?
	for( iCounter = 0; iCounter < giCurrentPersonalityQuizQuestion; iCounter++ )
	{
		// incrment until question is found
		iOffset +=iIMPQuestionLengths[ iCounter ];
	}

	// handle any female specifc questions
	if( fCharacterIsMale == FALSE )
	{
		OffSetQuestionForFemaleSpecificQuestions( &iOffset );
	}

	// how many answers are there?
	switch( iIMPQuestionLengths[ giCurrentPersonalityQuizQuestion ])
	{
	case ( 5 ):
			// 4 answers, write down the side, extra wide columns

			// question is at IMP_QUESTION_1 + iOffset
			// and there are 4 answers afterwards
		BltAnswerIndents( 4 );
			LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + 20, LAPTOP_SCREEN_WEB_UL_Y + 30, ( 460 ), ( INT16 )( IMP_QUESTION_1 + iOffset ), FONT10ARIAL, FONT_WHITE, TRUE, LEFT_JUSTIFIED);


			// answers
			LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + QTN_FIRST_COLUMN_X, LAPTOP_SCREEN_WEB_UL_Y + 100, ( 390 ), ( INT16 )( IMP_QUESTION_1 + iOffset + 1), FONT10ARIAL, 142, TRUE, LEFT_JUSTIFIED);
			LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + QTN_FIRST_COLUMN_X, LAPTOP_SCREEN_WEB_UL_Y + 150, ( 390 ), ( INT16 )( IMP_QUESTION_1 + iOffset + 2), FONT10ARIAL, 142, TRUE, 0);
		LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + QTN_FIRST_COLUMN_X, LAPTOP_SCREEN_WEB_UL_Y + 200, ( 390 ), ( INT16 )( IMP_QUESTION_1 + iOffset + 3), FONT10ARIAL, 142, TRUE, 0);
		LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + QTN_FIRST_COLUMN_X, LAPTOP_SCREEN_WEB_UL_Y + 250, ( 390 ), ( INT16 )( IMP_QUESTION_1 + iOffset + 4), FONT10ARIAL, 142, TRUE, 0);


			iOffset = 0;
	break;
		case ( 6 ):
		// question is at IMP_QUESTION_1 + iOffset
			// and there are 5 answers afterwards
			BltAnswerIndents( 5 );
			LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + 20, LAPTOP_SCREEN_WEB_UL_Y + 30, ( 460 ), ( INT16 )( IMP_QUESTION_1 + iOffset ), FONT10ARIAL, FONT_WHITE, TRUE, LEFT_JUSTIFIED);


			// answers
			LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + QTN_FIRST_COLUMN_X, LAPTOP_SCREEN_WEB_UL_Y + 100, ( 160 ), ( INT16 )( IMP_QUESTION_1 + iOffset + 1), FONT10ARIAL, 142, TRUE, 0);
			LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + QTN_FIRST_COLUMN_X, LAPTOP_SCREEN_WEB_UL_Y + 150, ( 160 ), ( INT16 )( IMP_QUESTION_1 + iOffset + 2), FONT10ARIAL, 142, TRUE, 0);
		LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + QTN_FIRST_COLUMN_X, LAPTOP_SCREEN_WEB_UL_Y + 200, ( 160 ), ( INT16 )( IMP_QUESTION_1 + iOffset + 3), FONT10ARIAL, 142, TRUE, 0);
		LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + QTN_FIRST_COLUMN_X, LAPTOP_SCREEN_WEB_UL_Y + 250, ( 160 ), ( INT16 )( IMP_QUESTION_1 + iOffset + 4), FONT10ARIAL, 142, TRUE, 0);
		LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X +QTN_SECOND_COLUMN_X, LAPTOP_SCREEN_WEB_UL_Y + 100, ( 160 ), ( INT16 )( IMP_QUESTION_1 + iOffset + 5), FONT10ARIAL, 142, TRUE, 0);


		break;
		case( 7 ):
		// question is at IMP_QUESTION_1 + iOffset
			// and there are 5 answers afterwards
		BltAnswerIndents( 6 );
			LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + 20, LAPTOP_SCREEN_WEB_UL_Y + 30, ( 460 ), ( INT16 )( IMP_QUESTION_1 + iOffset ), FONT10ARIAL, FONT_WHITE, TRUE, LEFT_JUSTIFIED);


			// answers
			LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + QTN_FIRST_COLUMN_X, LAPTOP_SCREEN_WEB_UL_Y + 100, ( 160 ), ( INT16 )( IMP_QUESTION_1 + iOffset + 1), FONT10ARIAL, 142, TRUE, 0);
			LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + QTN_FIRST_COLUMN_X, LAPTOP_SCREEN_WEB_UL_Y + 150, ( 160 ), ( INT16 )( IMP_QUESTION_1 + iOffset + 2), FONT10ARIAL, 142, TRUE, 0);
		LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + QTN_FIRST_COLUMN_X, LAPTOP_SCREEN_WEB_UL_Y + 200, ( 160 ), ( INT16 )( IMP_QUESTION_1 + iOffset + 3), FONT10ARIAL, 142, TRUE, 0);
		LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + QTN_FIRST_COLUMN_X, LAPTOP_SCREEN_WEB_UL_Y + 250, ( 160 ), ( INT16 )( IMP_QUESTION_1 + iOffset + 4), FONT10ARIAL, 142, TRUE, 0);
		LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + QTN_SECOND_COLUMN_X, LAPTOP_SCREEN_WEB_UL_Y + 100, ( 160 ), ( INT16 )( IMP_QUESTION_1 + iOffset + 5), FONT10ARIAL, 142, TRUE, 0);
		LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + QTN_SECOND_COLUMN_X, LAPTOP_SCREEN_WEB_UL_Y + 150, ( 160 ), ( INT16 )( IMP_QUESTION_1 + iOffset + 6), FONT10ARIAL, 142, TRUE, 0);


		break;
	case( 9 ):
		// question is at IMP_QUESTION_1 + iOffset
			// and there are 8 answers afterwards
		BltAnswerIndents( 8 );

			LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + 20, LAPTOP_SCREEN_WEB_UL_Y + 30, ( 460 ), ( INT16 )( IMP_QUESTION_1 + iOffset ), FONT10ARIAL, FONT_WHITE, TRUE, LEFT_JUSTIFIED);


			// answers
			LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + QTN_FIRST_COLUMN_X, LAPTOP_SCREEN_WEB_UL_Y + 100, ( 160 ), ( INT16 )( IMP_QUESTION_1 + iOffset + 1), FONT10ARIAL, 142, TRUE, 0);
			LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + QTN_FIRST_COLUMN_X, LAPTOP_SCREEN_WEB_UL_Y + 150, ( 160 ), ( INT16 )( IMP_QUESTION_1 + iOffset + 2), FONT10ARIAL, 142, TRUE, 0);
		LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + QTN_FIRST_COLUMN_X, LAPTOP_SCREEN_WEB_UL_Y + 200, ( 160 ), ( INT16 )( IMP_QUESTION_1 + iOffset + 3), FONT10ARIAL, 142, TRUE, 0);
		LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + QTN_FIRST_COLUMN_X, LAPTOP_SCREEN_WEB_UL_Y + 250, ( 160 ), ( INT16 )( IMP_QUESTION_1 + iOffset + 4), FONT10ARIAL, 142, TRUE, 0);
		LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + QTN_SECOND_COLUMN_X, LAPTOP_SCREEN_WEB_UL_Y + 100, ( 160 ), ( INT16 )( IMP_QUESTION_1 + iOffset + 5), FONT10ARIAL, 142, TRUE, 0);
		LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + QTN_SECOND_COLUMN_X, LAPTOP_SCREEN_WEB_UL_Y + 150, ( 160 ), ( INT16 )( IMP_QUESTION_1 + iOffset + 6), FONT10ARIAL, 142, TRUE, 0);
		LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + QTN_SECOND_COLUMN_X, LAPTOP_SCREEN_WEB_UL_Y + 200, ( 160 ), ( INT16 )( IMP_QUESTION_1 + iOffset + 7), FONT10ARIAL, 142, TRUE, 0);
		LoadAndDisplayIMPText( LAPTOP_SCREEN_UL_X + QTN_SECOND_COLUMN_X, LAPTOP_SCREEN_WEB_UL_Y + 250, ( 160 ), ( INT16 )( IMP_QUESTION_1 + iOffset + 8), FONT10ARIAL, 142, TRUE, 0);


		break;

	}

	return;
}

void OffSetQuestionForFemaleSpecificQuestions( INT32 *iCurrentOffset )
{
	INT32 iExtraOffSet = 0;
	BOOLEAN fOffSet = TRUE;

	// find the extra
	switch( giCurrentPersonalityQuizQuestion )
	{
		case( 0 ):
			iExtraOffSet = 0;
			break;
		case( 3 ):
			iExtraOffSet = iIMPQuestionLengths[ 0 ];
			break;
		case( 8 ):
			iExtraOffSet = iIMPQuestionLengths[ 0 ] + iIMPQuestionLengths[ 3 ];
			break;
		case( 9 ):
			iExtraOffSet = iIMPQuestionLengths[ 0 ] + iIMPQuestionLengths[ 3 ] + iIMPQuestionLengths[ 8 ];
			break;
		case( 13 ):
			iExtraOffSet = iIMPQuestionLengths[ 0 ] + iIMPQuestionLengths[ 3 ] + iIMPQuestionLengths[ 8 ] + iIMPQuestionLengths[ 9 ];
			break;
		default:
			fOffSet = FALSE;
			break;
	}

	if( fOffSet )
	{
		*iCurrentOffset = IMP_CON_3 - ( IMP_QUESTION_1 - 3 );

		*iCurrentOffset += iExtraOffSet;

	}
}
