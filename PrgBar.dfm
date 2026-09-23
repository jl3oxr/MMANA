object ProgressForm: TProgressForm
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = 'Calculating...'
  ClientHeight = 60
  ClientWidth = 200
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poMainFormCenter
  TextHeight = 15
  object Label1: TLabel
    Left = 160
    Top = 16
    Width = 35
    Height = 25
    Caption = 'Label1'
  end
  object ProgressBar1: TProgressBar
    Left = 5
    Top = 16
    Width = 150
    Height = 25
    TabOrder = 0
  end
end
