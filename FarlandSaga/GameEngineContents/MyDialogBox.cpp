#include "PreCompile.h"
#include"MyDialogBox.h"

MyDialogBox::MyDialogBox()
	:DialogStack_(0)
	, DialogLevel_(0)
	, DialogEnd_(false)
{

}
MyDialogBox::~MyDialogBox()
{

}
void MyDialogBox::Start()
{
	if (false == GameEngineInput::GetInst()->IsKey("NextDialog"))
	{
		GameEngineInput::GetInst()->CreateKey("NextDialog", VK_SPACE);
	}

	GetTransform().SetLocalPosition({ 0, 240, 1 });
	{
		DialogBoxRenderer01 = CreateComponent<GameEngineTextureRenderer>();
		DialogBoxRenderer01->GetTransform().SetLocalScale({ 921, 230, 0 });
		DialogBoxRenderer01->GetTransform().SetLocalPosition({ 0, 10,0 });

		DialogFaceRenderer01 = CreateComponent<GameEngineTextureRenderer>();
		DialogFaceRenderer01->GetTransform().SetLocalScale({ 360, 288, 0 });
		DialogFaceRenderer01->GetTransform().SetLocalPosition({ -250, 0,0 });

		DialogUpName = CreateComponent<GameEngineFontRenderer>();
		DialogUpName->SetColor({ 1.0f, 1.0f, 0.0f });
		DialogUpName->SetScreenPostion({ 430.0f, 50.0f });

		DialogUpText01 = CreateComponent<GameEngineFontRenderer>();
		DialogUpText01->SetColor({ 1.0f, 1.0f, 1.0f });
		DialogUpText01->SetScreenPostion({ 430.0f, 80.0f });

		DialogUpText02 = CreateComponent<GameEngineFontRenderer>();
		DialogUpText02->SetColor({ 1.0f, 1.0f, 1.0f });
		DialogUpText02->SetScreenPostion({ 430.0f, 110.0f });

		DialogUpText03 = CreateComponent<GameEngineFontRenderer>();
		DialogUpText03->SetColor({ 1.0f, 1.0f, 1.0f });
		DialogUpText03->SetScreenPostion({ 430.0f, 140.0f });

	}
	{
		DialogBoxRenderer02= CreateComponent<GameEngineTextureRenderer>();
		DialogBoxRenderer02->GetTransform().SetLocalScale({ 921, 230, 0 });
		DialogBoxRenderer02->GetTransform().SetLocalPosition({ 0,-490,1 });

		DialogFaceRenderer02 = CreateComponent<GameEngineTextureRenderer>();
		DialogFaceRenderer02->GetTransform().SetLocalScale({ 360, 288, 0 });
		DialogFaceRenderer02->GetTransform().SetLocalPosition({ 260, -510,0 });

		DialogDownName = CreateComponent<GameEngineFontRenderer>();
		DialogDownName->SetColor({ 1.0f, 1.0f, 0.0f });
		DialogDownName->SetScreenPostion({ 80.0f, 550.0f });

		DialogDownText01 = CreateComponent<GameEngineFontRenderer>();
		DialogDownText01->SetColor({ 1.0f, 1.0f, 1.0f });
		DialogDownText01->SetScreenPostion({ 80.0f, 580.0f });

		DialogDownText02 = CreateComponent<GameEngineFontRenderer>();
		DialogDownText02->SetColor({ 1.0f, 1.0f, 1.0f });
		DialogDownText02->SetScreenPostion({ 80.0f, 610.0f });

		DialogDownText03 = CreateComponent<GameEngineFontRenderer>();
		DialogDownText03->SetColor({ 1.0f, 1.0f, 1.0f });
		DialogDownText03->SetScreenPostion({ 80.0f, 640.0f });


	}
}

void MyDialogBox::Update(float _DeltaTime)
{

	if (true == GameEngineInput::GetInst()->IsDown("NextDialog"))
	{
		++DialogStack_;
	}
	if (DialogLevel_ == 10)
	{
		switch (DialogStack_)
		{
		case 1:
			DialogBoxRenderer01->SetTexture("DialogBox.png");
			DialogBoxRenderer01->On();
			DialogFaceRenderer01->SetTexture("face01a.png");
			DialogFaceRenderer01->On();
			DialogUpName->SetText("·¹¿Â", "ÈÞ¸Õ°íµñ");
			DialogUpText01->SetText("[¸¹ÀÌ ±â´Ù·ÈÁö!]", "ÈÞ¸Õ°íµñ");
			break;
		case 2:
			DialogBoxRenderer02->SetTexture("DialogBox.png");
			DialogBoxRenderer02->On();
			DialogFaceRenderer02->SetTexture("face02g.png");
			DialogFaceRenderer02->On();
			DialogDownName->SetText("¶öÇÁ", "ÈÞ¸Õ°íµñ");
			DialogDownText01->SetText("[¿Ö ²Ù¹°´ë´Â °Å¾ß.]", "ÈÞ¸Õ°íµñ");
			break;
		case 3:
			DialogFaceRenderer01->SetTexture("face01g.png");
			DialogUpText01->SetText("[¹Ì¾È¹Ì¾È. ¾Æ´Ï? ¾Æ¹öÁö´Â?]", "ÈÞ¸Õ°íµñ");
			break;
		case 4:
			DialogFaceRenderer02->SetTexture("face02a.png");
			DialogDownText01->SetText("[¸ÕÀú °¡¼Ì¾î.]", "ÈÞ¸Õ°íµñ");
			break;
		case 5:
			DialogFaceRenderer01->SetTexture("face01d.png");
			DialogUpText01->SetSize(60);
			DialogUpText01->SetText("[¹¹?!]", "ÈÞ¸Õ°íµñ");
			break;
		case 6:
			DialogFaceRenderer02->SetTexture("face02f.png");
			DialogDownText01->SetText("[³ó´ãÀÌ¾ß. ¸¶À» ÀÔ±¸¿¡¼­ ±â´Ù¸®°í °è¼Å.]", "ÈÞ¸Õ°íµñ");
			break;
		case 7:
			DialogFaceRenderer01->SetTexture("face01e.png");
			DialogUpText01->SetSize(23);
			DialogUpText01->SetText("[³î·¡Å°Áö ¸»¶ó±¸.]", "ÈÞ¸Õ°íµñ");
			break;
		case 8:
			DialogDownText01->SetText("[·¹¿ÂÀÌ ÀÏÂï ÀÏ¾î³ªÁö ¾Ê¾Æ¼­ ±×·¡.]", "ÈÞ¸Õ°íµñ");
			DialogDownText02->SetText("ÀÚ, ¼­µÑ·¯.]", "ÈÞ¸Õ°íµñ");
			break;
		case 9:
			DialogFaceRenderer01->SetTexture("face01a.png");
			DialogUpText01->SetText("[À¸, ÀÀ.]", "ÈÞ¸Õ°íµñ");
			break;
		case 10:
			DialogStack_ = 0;
			DialogEnd_ = true;
			break;
		default:
			DialogBoxRenderer01->Off();
			DialogFaceRenderer01->Off();
			DialogUpName->SetText(" ", "ÈÞ¸Õ°íµñ");
			DialogUpText01->SetText(" ", "ÈÞ¸Õ°íµñ");
			DialogUpText02->SetText(" ", "ÈÞ¸Õ°íµñ");
			DialogBoxRenderer02->Off();
			DialogFaceRenderer02->Off();
			DialogDownName->SetText(" ", "ÈÞ¸Õ°íµñ");
			DialogDownText01->SetText(" ", "ÈÞ¸Õ°íµñ");
			DialogDownText02->SetText(" ", "ÈÞ¸Õ°íµñ");
			break;
		}
	}
	else if (DialogLevel_ == 11)
	{
		switch (DialogStack_)
		{
		case 1:
			DialogBoxRenderer01->SetTexture("DialogBox.png");
			DialogBoxRenderer01->On();
			DialogFaceRenderer01->SetTexture("face02d.png");
			DialogFaceRenderer01->On();
			DialogUpName->SetText("¶öÇÁ", "ÈÞ¸Õ°íµñ");
			DialogUpText01->SetText("[¾Æ¹öÁö~!]", "ÈÞ¸Õ°íµñ");
			break;
		case 2:
			DialogBoxRenderer02->SetTexture("DialogBox.png");
			DialogBoxRenderer02->On();
			DialogFaceRenderer02->SetTexture("face04a.png");
			DialogFaceRenderer02->On();
			DialogDownName->SetText("ºê¶óÀÌ¾ð", "ÈÞ¸Õ°íµñ");
			DialogDownText01->SetText("[¾Æ, °Ü¿ì ¿Ô±º.]", "ÈÞ¸Õ°íµñ");
			break;
		case 3:
			DialogFaceRenderer01->SetTexture("face01e.png");
			DialogUpName->SetText("·¹¿Â", "ÈÞ¸Õ°íµñ");
			DialogUpText01->SetText("[ÁË¼ÛÇØ¿ä, ¾Æ¹öÁö.]", "ÈÞ¸Õ°íµñ");
			break;
		case 4:
			DialogFaceRenderer02->SetTexture("face02f.png");
			DialogDownName->SetText("¶öÇÁ", "ÈÞ¸Õ°íµñ");
			DialogDownText01->SetText("[Á¤¸» Àá²Ù·¯±â¶ó´Ï±î.]", "ÈÞ¸Õ°íµñ");
			break;
		case 5:
			DialogFaceRenderer01->SetTexture("face01a.png");
			DialogUpName->SetText("·¹¿Â", "ÈÞ¸Õ°íµñ");
			DialogUpText01->SetText("[¾îÁ¦ ¹ãÀº ±äÀåÇØ¼­ ½±°Ô Àáµé ¼ö ¾ø¾ú¾î.]", "ÈÞ¸Õ°íµñ");
			break;
		case 6:
			DialogFaceRenderer02->SetTexture("face04a.png");
			DialogDownName->SetText("ºê¶óÀÌ¾ð", "ÈÞ¸Õ°íµñ");
			DialogDownText01->SetText("[Èì... ±×·¯°í º¸´Ï µÑ ´Ù ¿Õµµ¿¡", "ÈÞ¸Õ°íµñ");
			DialogDownText02->SetText(" °¡´Â °Ç Ã³À½ÀÌÁö.]", "ÈÞ¸Õ°íµñ");
			break;
		case 7:
			DialogFaceRenderer01->SetTexture("face01j.png");
			DialogUpName->SetText("·¹¿Â", "ÈÞ¸Õ°íµñ");
			DialogUpText01->SetText("[ÀÀ! »¡¸® º¸°í ½Í¾î.]", "ÈÞ¸Õ°íµñ");
			break;
		case 8:
			DialogFaceRenderer02->SetTexture("face02f.png");
			DialogDownName->SetText("¶öÇÁ", "ÈÞ¸Õ°íµñ");
			DialogDownText01->SetText("[½Ã°£ÀÌ Áö³ªµµ ¾î¸°¾Ö °°´Ù´Ï±î.]", "ÈÞ¸Õ°íµñ");
			DialogDownText02->SetText(" ", "ÈÞ¸Õ°íµñ");
			break;
		case 9:
			DialogFaceRenderer01->SetTexture("face01a.png");
			DialogUpName->SetText("·¹¿Â", "ÈÞ¸Õ°íµñ");
			DialogUpText01->SetText("[±×·¸°Ô ¸»ÇÏ´Â ¶öÇÁµµ ÀÏºÎ·¯ »õ ¿ÊÀ»", "ÈÞ¸Õ°íµñ");
			DialogUpText02->SetText(" »ç³õ°í´Â ¹¹. ³²ÀÇ ¸» ÇÒ °Í ¾ø¾î.]", "ÈÞ¸Õ°íµñ");
			break;
		case 10:
			DialogFaceRenderer02->SetTexture("face02c.png");
			DialogDownName->SetText("¶öÇÁ", "ÈÞ¸Õ°íµñ");
			DialogDownText01->SetText("[±×·¡¼­ ·¹¿ÂÀº ²¿¸¶¶ó°í ÇÏÀÝ¾Æ.", "ÈÞ¸Õ°íµñ");
			DialogDownText02->SetText(" »ý°¢ÇØ ºÁ. ¿ì¸®´Â ²ÉÀÇ µµ½Ã '¹ö½º'", "ÈÞ¸Õ°íµñ");
			DialogDownText03->SetText(" ·Î °¡´Â °ÅÁö?]", "ÈÞ¸Õ°íµñ");
			break;
		case 11:
			DialogFaceRenderer02->SetTexture("face02d.png");
			DialogDownName->SetText("¶öÇÁ", "ÈÞ¸Õ°íµñ");
			DialogDownText01->SetText("[µµ½Ã¶ó°í ÇÏ¸é ´ç¿¬È÷ ¾Æ¸§´Ù¿î ¿©ÀÚµéÀÌ", "ÈÞ¸Õ°íµñ");
			DialogDownText02->SetText(" ¾öÃ»³ª°Ô ÀÖ°ÚÁö!]", "ÈÞ¸Õ°íµñ");
			DialogDownText03->SetText(" ", "ÈÞ¸Õ°íµñ");
			break;
		case 12:
			DialogFaceRenderer01->SetTexture("face01a.png");
			DialogUpName->SetText("·¹¿Â", "ÈÞ¸Õ°íµñ");
			DialogUpText01->SetText("[¹àÈûÁõ!]", "ÈÞ¸Õ°íµñ");
			DialogUpText02->SetText(" ", "ÈÞ¸Õ°íµñ");
			break;
		case 13:
			DialogFaceRenderer02->SetTexture("face02f.png");
			DialogDownName->SetText("¶öÇÁ", "ÈÞ¸Õ°íµñ");
			DialogDownText01->SetText("[Á»´õ ÁÁÀº Ç¥ÇöÀº ¾µ ¼ö ¾ø¾î?", "ÈÞ¸Õ°íµñ");
			DialogDownText02->SetText(" ¾ðÁ¦ ¿î¸íÀûÀÎ ¸¸³²ÀÌ Ã£¾Æ¿ÃÁöµµ", "ÈÞ¸Õ°íµñ");
			DialogDownText03->SetText(" ¸ð¸£ÀÝ¾Æ.]", "ÈÞ¸Õ°íµñ");
			break;
		case 14:
			DialogFaceRenderer01->SetTexture("face01e.png");
			DialogUpName->SetText("·¹¿Â", "ÈÞ¸Õ°íµñ");
			DialogUpText01->SetText("[¿î¸íÀûÀÎ ¸¸³²ÀÌ¶ó±¸...]", "ÈÞ¸Õ°íµñ");
			break;
		case 15:
			DialogFaceRenderer02->SetTexture("face04c.png");
			DialogDownName->SetText("ºê¶óÀÌ¾ð", "ÈÞ¸Õ°íµñ");
			DialogDownText01->SetText("[ÇÏÇÏÇÏ. ¼¼»óÀº ±×·¸°Ô ½±Áö ¾Ê´Ù±¸.]", "ÈÞ¸Õ°íµñ");
			DialogDownText02->SetText(" ", "ÈÞ¸Õ°íµñ");
			DialogDownText03->SetText(" ", "ÈÞ¸Õ°íµñ");
			break;
		case 16:
			DialogFaceRenderer01->SetTexture("face02g.png");
			DialogUpName->SetText("¶öÇÁ", "ÈÞ¸Õ°íµñ");
			DialogUpText01->SetText("[¾Æ¹öÁö...]", "ÈÞ¸Õ°íµñ");
			break;
		case 17:
			DialogFaceRenderer01->SetTexture("face01a.png");
			DialogUpName->SetText("·¹¿Â", "ÈÞ¸Õ°íµñ");
			DialogUpText01->SetText("[¾Æ¹öÁö, ³»ÀÏ ¿Õµµ¿¡¼­ ¹«½¼ÀÏÀÌ ÀÖÁö¿ä?]", "ÈÞ¸Õ°íµñ");
			break;
		case 18:
			DialogFaceRenderer02->SetTexture("face04c.png");
			DialogDownName->SetText("ºê¶óÀÌ¾ð", "ÈÞ¸Õ°íµñ");
			DialogDownText01->SetText("[±Û½ê...ÀÚ, °ÉÀ¸¸é¼­ ¸»ÇØÁÖ¸¶,]", "ÈÞ¸Õ°íµñ");
			break;
		case 19:
			DialogStack_ = 0;
			DialogEnd_ = true;
			break;
		default:
			DialogBoxRenderer01->Off();
			DialogFaceRenderer01->Off();
			DialogUpName->SetText(" ", "ÈÞ¸Õ°íµñ");
			DialogUpText01->SetText(" ", "ÈÞ¸Õ°íµñ");
			DialogUpText02->SetText(" ", "ÈÞ¸Õ°íµñ");
			DialogBoxRenderer02->Off();
			DialogFaceRenderer02->Off();
			DialogDownName->SetText(" ", "ÈÞ¸Õ°íµñ");
			DialogDownText01->SetText(" ", "ÈÞ¸Õ°íµñ");
			DialogDownText02->SetText(" ", "ÈÞ¸Õ°íµñ");
			DialogDownText03->SetText(" ", "ÈÞ¸Õ°íµñ");
			break;
		}
	}
	else if (DialogLevel_ == 12)
	{
		switch (DialogStack_)
		{
		case 1:
			DialogBoxRenderer02->SetTexture("DialogBox.png");
			DialogBoxRenderer02->On();
			DialogFaceRenderer02->SetTexture("face02e.png");
			DialogFaceRenderer02->On();
			DialogDownName->SetText("¶öÇÁ", "ÈÞ¸Õ°íµñ");
			DialogDownText01->SetText("[¹¹¹¹¹¹¹¹³Ä!?]", "ÈÞ¸Õ°íµñ");
			break;
		case 2:
			DialogBoxRenderer01->SetTexture("DialogBox.png");
			DialogBoxRenderer01->On();
			DialogFaceRenderer01->SetTexture("face01d.png");
			DialogFaceRenderer01->On();
			DialogUpName->SetText("·¹¿Â", "ÈÞ¸Õ°íµñ");
			DialogUpText01->SetText("[±«¹°ÀÌ´Ù!]", "ÈÞ¸Õ°íµñ");
			break;
		case 3:
			DialogFaceRenderer02->SetTexture("face04e.png");
			DialogDownName->SetText("ºê¶óÀÌ¾ð", "ÈÞ¸Õ°íµñ");
			DialogDownText01->SetText("[ÃÖ±Ù ´Ã¾ú´Ù´Â ¸»Àº µé¾úÁö¸¸...", "ÈÞ¸Õ°íµñ");
			DialogDownText02->SetText(" »ç½ÇÀÌ¶ó´Ï.}", "ÈÞ¸Õ°íµñ");
			break;
		case 4:
			DialogUpName->SetText("·¹¿Â", "ÈÞ¸Õ°íµñ");
			DialogUpText01->SetText("[¾Æ¾Æ¾Æ¹öÁö! ¾î¶± ÇÏÁö¿ä!?]", "ÈÞ¸Õ°íµñ");
			break;
		case 5:
			DialogFaceRenderer02->SetTexture("face04b.png");
			DialogDownName->SetText("ºê¶óÀÌ¾ð", "ÈÞ¸Õ°íµñ");
			DialogDownText01->SetText("[´çÈ²ÇÏÁö ¸»°Å¶ó!! ÀÌ·± ¶§¸¦ À§ÇØ", "ÈÞ¸Õ°íµñ");
			DialogDownText02->SetText(" ¾î¸± ¶§ºÎÅÍ ÈÆ·ÃÀ» ¹Þ¾ÒÀÝ´À³Ä!}", "ÈÞ¸Õ°íµñ");
			break;
		case 6:
			DialogFaceRenderer02->SetTexture("face04a.png");
			DialogDownName->SetText("ºê¶óÀÌ¾ð", "ÈÞ¸Õ°íµñ");
			DialogDownText01->SetText("[¾ðÁ¦³ª °¡¸£ÃÄÁØ ´ë·Î ÇÏ¸é", "ÈÞ¸Õ°íµñ");
			DialogDownText02->SetText(" ³«½ÂÀ» °ÅµÑ »ó´ë´Ù.}", "ÈÞ¸Õ°íµñ");
			break;
		case 7:
			DialogFaceRenderer01->SetTexture("face02d.png");
			DialogUpName->SetText("¶öÇÁ", "ÈÞ¸Õ°íµñ");
			DialogUpText01->SetText("[ÁÁ¾Æ! ¿©±â´Â ³»°¡ ÀüºÎ Ã³¸®ÇÏÁö!]", "ÈÞ¸Õ°íµñ");
			break;
		case 8:
			DialogStack_ = 0;
			DialogEnd_ = true;
			break;
		default:
			DialogBoxRenderer01->Off();
			DialogFaceRenderer01->Off();
			DialogUpName->SetText(" ", "ÈÞ¸Õ°íµñ");
			DialogUpText01->SetText(" ", "ÈÞ¸Õ°íµñ");
			DialogUpText02->SetText(" ", "ÈÞ¸Õ°íµñ");
			DialogBoxRenderer02->Off();
			DialogFaceRenderer02->Off();
			DialogDownName->SetText(" ", "ÈÞ¸Õ°íµñ");
			DialogDownText01->SetText(" ", "ÈÞ¸Õ°íµñ");
			DialogDownText02->SetText(" ", "ÈÞ¸Õ°íµñ");
			DialogDownText03->SetText(" ", "ÈÞ¸Õ°íµñ");
			break;
		}
	}
	else if (DialogLevel_ == 13)
	{
		switch (DialogStack_)
		{
		case 1:
			DialogBoxRenderer01->SetTexture("DialogBox.png");
			DialogBoxRenderer01->On();
			DialogFaceRenderer01->SetTexture("face04b.png");
			DialogFaceRenderer01->On();
			DialogUpName->SetText("ºê¶óÀÌ¾ð", "ÈÞ¸Õ°íµñ");
			DialogUpText01->SetText("[¸ÛÃ»ÀÌ! ÀûÀÌ ¾àÇÏ´Ù°í È¥ÀÚ µ¹ÁøÇØ¼­,", "ÈÞ¸Õ°íµñ");
			DialogUpText02->SetText(" °á±¹Àº ¼ö¸¹Àº Àû¿¡°Ô µÑ·¯½Î¿©", "ÈÞ¸Õ°íµñ");
			DialogUpText03->SetText(" Á×Àº ³à¼®µµ ÀÖ´Ù±¸!]", "ÈÞ¸Õ°íµñ");
			break;
		case 2:
			DialogBoxRenderer02->SetTexture("DialogBox.png");
			DialogBoxRenderer02->On();
			DialogFaceRenderer02->SetTexture("face01a.png");
			DialogFaceRenderer02->On();
			DialogDownName->SetText("·¹¿Â", "ÈÞ¸Õ°íµñ");
			DialogDownText01->SetText("[¶öÇÁ, Áö±ÝÀº ¸ðµÎ ½Î¿ì´Â ÆíÀÌ ÁÁ°Ú¾î.]", "ÈÞ¸Õ°íµñ");
			break;
		case 3:
			DialogFaceRenderer01->SetTexture("face02g.png");
			DialogUpName->SetText("¶öÇÁ", "ÈÞ¸Õ°íµñ");
			DialogUpText01->SetText("[±×...±×·¡. ¹«¸®´Â ¾ÈµÅ. ÀÀ.]", "ÈÞ¸Õ°íµñ");
			DialogUpText02->SetText(" ", "ÈÞ¸Õ°íµñ");
			DialogUpText03->SetText(" ", "ÈÞ¸Õ°íµñ");
			break;
		case 4:
			DialogStack_ = 0;
			DialogEnd_ = true;
			break;
		default:
			DialogBoxRenderer01->Off();
			DialogFaceRenderer01->Off();
			DialogUpName->SetText(" ", "ÈÞ¸Õ°íµñ");
			DialogUpText01->SetText(" ", "ÈÞ¸Õ°íµñ");
			DialogUpText02->SetText(" ", "ÈÞ¸Õ°íµñ");
			DialogUpText03->SetText(" ", "ÈÞ¸Õ°íµñ");
			DialogBoxRenderer02->Off();
			DialogFaceRenderer02->Off();
			DialogDownName->SetText(" ", "ÈÞ¸Õ°íµñ");
			DialogDownText01->SetText(" ", "ÈÞ¸Õ°íµñ");
			DialogDownText02->SetText(" ", "ÈÞ¸Õ°íµñ");
			DialogDownText03->SetText(" ", "ÈÞ¸Õ°íµñ");
			break;
		}
	}
}
void MyDialogBox::End()
{

}
