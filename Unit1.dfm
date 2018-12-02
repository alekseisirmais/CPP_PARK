object Form1: TForm1
  Left = 0
  Top = 0
  ActiveControl = Memo1
  Caption = 'Form1'
  ClientHeight = 451
  ClientWidth = 738
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Memo1: TMemo
    Left = 8
    Top = 8
    Width = 393
    Height = 401
    Lines.Strings = (
      'Memo1')
    TabOrder = 0
  end
  object Button1: TButton
    Left = 424
    Top = 24
    Width = 75
    Height = 25
    Caption = 'Start server'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 432
    Top = 120
    Width = 75
    Height = 25
    Caption = 'Clear Memo'
    TabOrder = 2
    OnClick = Button2Click
  end
  object Button5: TButton
    Left = 424
    Top = 168
    Width = 75
    Height = 25
    Caption = 'View USB list'
    TabOrder = 3
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 424
    Top = 264
    Width = 75
    Height = 25
    Caption = 'stop'
    TabOrder = 4
    OnClick = Button6Click
  end
  object Button3: TButton
    Left = 424
    Top = 72
    Width = 75
    Height = 25
    Caption = 'run'
    TabOrder = 5
    OnClick = Button3Click
  end
  object ServerSocket1: TServerSocket
    Active = False
    Port = 0
    ServerType = stNonBlocking
    OnClientConnect = MyOnClientConnectEvent
    Left = 440
    Top = 336
  end
end
