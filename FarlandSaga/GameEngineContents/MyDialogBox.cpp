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
			DialogUpName->SetText("����", "�޸հ��");
			DialogUpText01->SetText("[���� ��ٷ���!]", "�޸հ��");
			break;
		case 2:
			DialogBoxRenderer02->SetTexture("DialogBox.png");
			DialogBoxRenderer02->On();
			DialogFaceRenderer02->SetTexture("face02g.png");
			DialogFaceRenderer02->On();
			DialogDownName->SetText("����", "�޸հ��");
			DialogDownText01->SetText("[�� �ٹ���� �ž�.]", "�޸հ��");
			break;
		case 3:
			DialogFaceRenderer01->SetTexture("face01g.png");
			DialogUpText01->SetText("[�̾ȹ̾�. �ƴ�? �ƹ�����?]", "�޸հ��");
			break;
		case 4:
			DialogFaceRenderer02->SetTexture("face02a.png");
			DialogDownText01->SetText("[���� ���̾�.]", "�޸հ��");
			break;
		case 5:
			DialogFaceRenderer01->SetTexture("face01d.png");
			DialogUpText01->SetSize(60);
			DialogUpText01->SetText("[��?!]", "�޸հ��");
			break;
		case 6:
			DialogFaceRenderer02->SetTexture("face02f.png");
			DialogDownText01->SetText("[����̾�. ���� �Ա����� ��ٸ��� ���.]", "�޸հ��");
			break;
		case 7:
			DialogFaceRenderer01->SetTexture("face01e.png");
			DialogUpText01->SetSize(23);
			DialogUpText01->SetText("[�Ű�� ����.]", "�޸հ��");
			break;
		case 8:
			DialogDownText01->SetText("[������ ���� �Ͼ�� �ʾƼ� �׷�.]", "�޸հ��");
			DialogDownText02->SetText("��, ���ѷ�.]", "�޸հ��");
			break;
		case 9:
			DialogFaceRenderer01->SetTexture("face01a.png");
			DialogUpText01->SetText("[��, ��.]", "�޸հ��");
			break;
		case 10:
			DialogStack_ = 0;
			DialogEnd_ = true;
			break;
		default:
			DialogBoxRenderer01->Off();
			DialogFaceRenderer01->Off();
			DialogUpName->SetText(" ", "�޸հ��");
			DialogUpText01->SetText(" ", "�޸հ��");
			DialogUpText02->SetText(" ", "�޸հ��");
			DialogBoxRenderer02->Off();
			DialogFaceRenderer02->Off();
			DialogDownName->SetText(" ", "�޸հ��");
			DialogDownText01->SetText(" ", "�޸հ��");
			DialogDownText02->SetText(" ", "�޸հ��");
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
			DialogUpName->SetText("����", "�޸հ��");
			DialogUpText01->SetText("[�ƹ���~!]", "�޸հ��");
			break;
		case 2:
			DialogBoxRenderer02->SetTexture("DialogBox.png");
			DialogBoxRenderer02->On();
			DialogFaceRenderer02->SetTexture("face04a.png");
			DialogFaceRenderer02->On();
			DialogDownName->SetText("����̾�", "�޸հ��");
			DialogDownText01->SetText("[��, �ܿ� �Ա�.]", "�޸հ��");
			break;
		case 3:
			DialogFaceRenderer01->SetTexture("face01e.png");
			DialogUpName->SetText("����", "�޸հ��");
			DialogUpText01->SetText("[�˼��ؿ�, �ƹ���.]", "�޸հ��");
			break;
		case 4:
			DialogFaceRenderer02->SetTexture("face02f.png");
			DialogDownName->SetText("����", "�޸հ��");
			DialogDownText01->SetText("[���� ��ٷ����ϱ�.]", "�޸հ��");
			break;
		case 5:
			DialogFaceRenderer01->SetTexture("face01a.png");
			DialogUpName->SetText("����", "�޸հ��");
			DialogUpText01->SetText("[���� ���� �����ؼ� ���� ��� �� ������.]", "�޸հ��");
			break;
		case 6:
			DialogFaceRenderer02->SetTexture("face04a.png");
			DialogDownName->SetText("����̾�", "�޸հ��");
			DialogDownText01->SetText("[��... �׷��� ���� �� �� �յ���", "�޸հ��");
			DialogDownText02->SetText(" ���� �� ó������.]", "�޸հ��");
			break;
		case 7:
			DialogFaceRenderer01->SetTexture("face01j.png");
			DialogUpName->SetText("����", "�޸հ��");
			DialogUpText01->SetText("[��! ���� ���� �;�.]", "�޸հ��");
			break;
		case 8:
			DialogFaceRenderer02->SetTexture("face02f.png");
			DialogDownName->SetText("����", "�޸հ��");
			DialogDownText01->SetText("[�ð��� ������ ��� ���ٴϱ�.]", "�޸հ��");
			DialogDownText02->SetText(" ", "�޸հ��");
			break;
		case 9:
			DialogFaceRenderer01->SetTexture("face01a.png");
			DialogUpName->SetText("����", "�޸հ��");
			DialogUpText01->SetText("[�׷��� ���ϴ� ������ �Ϻη� �� ����", "�޸հ��");
			DialogUpText02->SetText(" ������ ��. ���� �� �� �� ����.]", "�޸հ��");
			break;
		case 10:
			DialogFaceRenderer02->SetTexture("face02c.png");
			DialogDownName->SetText("����", "�޸հ��");
			DialogDownText01->SetText("[�׷��� ������ ������� ���ݾ�.", "�޸հ��");
			DialogDownText02->SetText(" ������ ��. �츮�� ���� ���� '����'", "�޸հ��");
			DialogDownText03->SetText(" �� ���� ����?]", "�޸հ��");
			break;
		case 11:
			DialogFaceRenderer02->SetTexture("face02d.png");
			DialogDownName->SetText("����", "�޸հ��");
			DialogDownText01->SetText("[���ö�� �ϸ� �翬�� �Ƹ��ٿ� ���ڵ���", "�޸հ��");
			DialogDownText02->SetText(" ��û���� �ְ���!]", "�޸հ��");
			DialogDownText03->SetText(" ", "�޸հ��");
			break;
		case 12:
			DialogFaceRenderer01->SetTexture("face01a.png");
			DialogUpName->SetText("����", "�޸հ��");
			DialogUpText01->SetText("[������!]", "�޸հ��");
			DialogUpText02->SetText(" ", "�޸հ��");
			break;
		case 13:
			DialogFaceRenderer02->SetTexture("face02f.png");
			DialogDownName->SetText("����", "�޸հ��");
			DialogDownText01->SetText("[���� ���� ǥ���� �� �� ����?", "�޸հ��");
			DialogDownText02->SetText(" ���� ������� ������ ã�ƿ�����", "�޸հ��");
			DialogDownText03->SetText(" ���ݾ�.]", "�޸հ��");
			break;
		case 14:
			DialogFaceRenderer01->SetTexture("face01e.png");
			DialogUpName->SetText("����", "�޸հ��");
			DialogUpText01->SetText("[������� �����̶�...]", "�޸հ��");
			break;
		case 15:
			DialogFaceRenderer02->SetTexture("face04c.png");
			DialogDownName->SetText("����̾�", "�޸հ��");
			DialogDownText01->SetText("[������. ������ �׷��� ���� �ʴٱ�.]", "�޸հ��");
			DialogDownText02->SetText(" ", "�޸հ��");
			DialogDownText03->SetText(" ", "�޸հ��");
			break;
		case 16:
			DialogFaceRenderer01->SetTexture("face02g.png");
			DialogUpName->SetText("����", "�޸հ��");
			DialogUpText01->SetText("[�ƹ���...]", "�޸հ��");
			break;
		case 17:
			DialogFaceRenderer01->SetTexture("face01a.png");
			DialogUpName->SetText("����", "�޸հ��");
			DialogUpText01->SetText("[�ƹ���, ���� �յ����� �������� ������?]", "�޸հ��");
			break;
		case 18:
			DialogFaceRenderer02->SetTexture("face04c.png");
			DialogDownName->SetText("����̾�", "�޸հ��");
			DialogDownText01->SetText("[�۽�...��, �����鼭 �����ָ�,]", "�޸հ��");
			break;
		case 19:
			DialogStack_ = 0;
			DialogEnd_ = true;
			break;
		default:
			DialogBoxRenderer01->Off();
			DialogFaceRenderer01->Off();
			DialogUpName->SetText(" ", "�޸հ��");
			DialogUpText01->SetText(" ", "�޸հ��");
			DialogUpText02->SetText(" ", "�޸հ��");
			DialogBoxRenderer02->Off();
			DialogFaceRenderer02->Off();
			DialogDownName->SetText(" ", "�޸հ��");
			DialogDownText01->SetText(" ", "�޸հ��");
			DialogDownText02->SetText(" ", "�޸հ��");
			DialogDownText03->SetText(" ", "�޸հ��");
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
			DialogDownName->SetText("����", "�޸հ��");
			DialogDownText01->SetText("[����������!?]", "�޸հ��");
			break;
		case 2:
			DialogBoxRenderer01->SetTexture("DialogBox.png");
			DialogBoxRenderer01->On();
			DialogFaceRenderer01->SetTexture("face01d.png");
			DialogFaceRenderer01->On();
			DialogUpName->SetText("����", "�޸հ��");
			DialogUpText01->SetText("[�����̴�!]", "�޸հ��");
			break;
		case 3:
			DialogFaceRenderer02->SetTexture("face04e.png");
			DialogDownName->SetText("����̾�", "�޸հ��");
			DialogDownText01->SetText("[�ֱ� �þ��ٴ� ���� �������...", "�޸հ��");
			DialogDownText02->SetText(" ����̶��.}", "�޸հ��");
			break;
		case 4:
			DialogUpName->SetText("����", "�޸հ��");
			DialogUpText01->SetText("[�ƾƾƹ���! � ������!?]", "�޸հ��");
			break;
		case 5:
			DialogFaceRenderer02->SetTexture("face04b.png");
			DialogDownName->SetText("����̾�", "�޸հ��");
			DialogDownText01->SetText("[��Ȳ���� ���Ŷ�!! �̷� ���� ����", "�޸հ��");
			DialogDownText02->SetText(" � ������ �Ʒ��� �޾��ݴ���!}", "�޸հ��");
			break;
		case 6:
			DialogFaceRenderer02->SetTexture("face04a.png");
			DialogDownName->SetText("����̾�", "�޸հ��");
			DialogDownText01->SetText("[������ �������� ��� �ϸ�", "�޸հ��");
			DialogDownText02->SetText(" ������ �ŵ� ����.}", "�޸հ��");
			break;
		case 7:
			DialogFaceRenderer01->SetTexture("face02d.png");
			DialogUpName->SetText("����", "�޸հ��");
			DialogUpText01->SetText("[����! ����� ���� ���� ó������!]", "�޸հ��");
			break;
		case 8:
			DialogStack_ = 0;
			DialogEnd_ = true;
			break;
		default:
			DialogBoxRenderer01->Off();
			DialogFaceRenderer01->Off();
			DialogUpName->SetText(" ", "�޸հ��");
			DialogUpText01->SetText(" ", "�޸հ��");
			DialogUpText02->SetText(" ", "�޸հ��");
			DialogBoxRenderer02->Off();
			DialogFaceRenderer02->Off();
			DialogDownName->SetText(" ", "�޸հ��");
			DialogDownText01->SetText(" ", "�޸հ��");
			DialogDownText02->SetText(" ", "�޸հ��");
			DialogDownText03->SetText(" ", "�޸հ��");
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
			DialogUpName->SetText("����̾�", "�޸հ��");
			DialogUpText01->SetText("[��û��! ���� ���ϴٰ� ȥ�� �����ؼ�,", "�޸հ��");
			DialogUpText02->SetText(" �ᱹ�� ������ ������ �ѷ��ο�", "�޸հ��");
			DialogUpText03->SetText(" ���� �༮�� �ִٱ�!]", "�޸հ��");
			break;
		case 2:
			DialogBoxRenderer02->SetTexture("DialogBox.png");
			DialogBoxRenderer02->On();
			DialogFaceRenderer02->SetTexture("face01a.png");
			DialogFaceRenderer02->On();
			DialogDownName->SetText("����", "�޸հ��");
			DialogDownText01->SetText("[����, ������ ��� �ο�� ���� ���ھ�.]", "�޸հ��");
			break;
		case 3:
			DialogFaceRenderer01->SetTexture("face02g.png");
			DialogUpName->SetText("����", "�޸հ��");
			DialogUpText01->SetText("[��...�׷�. ������ �ȵ�. ��.]", "�޸հ��");
			DialogUpText02->SetText(" ", "�޸հ��");
			DialogUpText03->SetText(" ", "�޸հ��");
			break;
		case 4:
			DialogStack_ = 0;
			DialogEnd_ = true;
			break;
		default:
			DialogBoxRenderer01->Off();
			DialogFaceRenderer01->Off();
			DialogUpName->SetText(" ", "�޸հ��");
			DialogUpText01->SetText(" ", "�޸հ��");
			DialogUpText02->SetText(" ", "�޸հ��");
			DialogUpText03->SetText(" ", "�޸հ��");
			DialogBoxRenderer02->Off();
			DialogFaceRenderer02->Off();
			DialogDownName->SetText(" ", "�޸հ��");
			DialogDownText01->SetText(" ", "�޸հ��");
			DialogDownText02->SetText(" ", "�޸հ��");
			DialogDownText03->SetText(" ", "�޸հ��");
			break;
		}
	}
}
void MyDialogBox::End()
{

}
