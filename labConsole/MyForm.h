#pragma once

namespace labConsole {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lbl_titlerez;
	private: System::Windows::Forms::Label^ lbl_rez;
	private: System::Windows::Forms::GroupBox^ gb_spp_types;
	private: System::Windows::Forms::RadioButton^ rb_short;
	private: System::Windows::Forms::RadioButton^ rb_double;

	private: System::Windows::Forms::RadioButton^ rb_float;
	private: System::Windows::Forms::RadioButton^ rb_char;
	private: System::Windows::Forms::RadioButton^ rb_long;
	private: System::Windows::Forms::Button^ btn_close;


	protected:


	protected:

	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->lbl_titlerez = (gcnew System::Windows::Forms::Label());
			this->lbl_rez = (gcnew System::Windows::Forms::Label());
			this->gb_spp_types = (gcnew System::Windows::Forms::GroupBox());
			this->rb_double = (gcnew System::Windows::Forms::RadioButton());
			this->rb_float = (gcnew System::Windows::Forms::RadioButton());
			this->rb_char = (gcnew System::Windows::Forms::RadioButton());
			this->rb_long = (gcnew System::Windows::Forms::RadioButton());
			this->rb_short = (gcnew System::Windows::Forms::RadioButton());
			this->btn_close = (gcnew System::Windows::Forms::Button());
			this->gb_spp_types->SuspendLayout();
			this->SuspendLayout();
			// 
			// lbl_titlerez
			// 
			this->lbl_titlerez->AutoSize = true;
			this->lbl_titlerez->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lbl_titlerez->Location = System::Drawing::Point(30, 31);
			this->lbl_titlerez->Name = L"lbl_titlerez";
			this->lbl_titlerez->Size = System::Drawing::Size(139, 29);
			this->lbl_titlerez->TabIndex = 0;
			this->lbl_titlerez->Text = L"Size(bytes):";
			// 
			// lbl_rez
			// 
			this->lbl_rez->AutoSize = true;
			this->lbl_rez->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lbl_rez->ForeColor = System::Drawing::SystemColors::Highlight;
			this->lbl_rez->Location = System::Drawing::Point(457, 10);
			this->lbl_rez->Name = L"lbl_rez";
			this->lbl_rez->Size = System::Drawing::Size(24, 55);
			this->lbl_rez->TabIndex = 1;
			this->lbl_rez->Text = L"\r\n";
			// 
			// gb_spp_types
			// 
			this->gb_spp_types->Controls->Add(this->rb_double);
			this->gb_spp_types->Controls->Add(this->rb_float);
			this->gb_spp_types->Controls->Add(this->rb_char);
			this->gb_spp_types->Controls->Add(this->rb_long);
			this->gb_spp_types->Controls->Add(this->rb_short);
			this->gb_spp_types->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->gb_spp_types->Location = System::Drawing::Point(25, 85);
			this->gb_spp_types->Name = L"gb_spp_types";
			this->gb_spp_types->Size = System::Drawing::Size(316, 202);
			this->gb_spp_types->TabIndex = 2;
			this->gb_spp_types->TabStop = false;
			this->gb_spp_types->Text = L"Select type: ";
			// 
			// rb_double
			// 
			this->rb_double->AutoSize = true;
			this->rb_double->Location = System::Drawing::Point(7, 174);
			this->rb_double->Name = L"rb_double";
			this->rb_double->Size = System::Drawing::Size(95, 29);
			this->rb_double->TabIndex = 7;
			this->rb_double->TabStop = true;
			this->rb_double->Text = L"double";
			this->rb_double->UseVisualStyleBackColor = true;
			this->rb_double->Click += gcnew System::EventHandler(this, &MyForm::rb_double_Click);
			// 
			// rb_float
			// 
			this->rb_float->AutoSize = true;
			this->rb_float->Location = System::Drawing::Point(7, 138);
			this->rb_float->Name = L"rb_float";
			this->rb_float->Size = System::Drawing::Size(71, 29);
			this->rb_float->TabIndex = 6;
			this->rb_float->TabStop = true;
			this->rb_float->Text = L"float";
			this->rb_float->UseVisualStyleBackColor = true;
			this->rb_float->Click += gcnew System::EventHandler(this, &MyForm::rb_float_Click);
			// 
			// rb_char
			// 
			this->rb_char->AutoSize = true;
			this->rb_char->Location = System::Drawing::Point(7, 102);
			this->rb_char->Name = L"rb_char";
			this->rb_char->Size = System::Drawing::Size(72, 29);
			this->rb_char->TabIndex = 5;
			this->rb_char->TabStop = true;
			this->rb_char->Text = L"char";
			this->rb_char->UseVisualStyleBackColor = true;
			this->rb_char->Click += gcnew System::EventHandler(this, &MyForm::rb_char_Click);
			// 
			// rb_long
			// 
			this->rb_long->AutoSize = true;
			this->rb_long->Location = System::Drawing::Point(10, 66);
			this->rb_long->Name = L"rb_long";
			this->rb_long->Size = System::Drawing::Size(71, 29);
			this->rb_long->TabIndex = 4;
			this->rb_long->TabStop = true;
			this->rb_long->Text = L"long";
			this->rb_long->UseVisualStyleBackColor = true;
			this->rb_long->Click += gcnew System::EventHandler(this, &MyForm::rb_long_Click);
			// 
			// rb_short
			// 
			this->rb_short->AutoSize = true;
			this->rb_short->Location = System::Drawing::Point(10, 30);
			this->rb_short->Name = L"rb_short";
			this->rb_short->Size = System::Drawing::Size(78, 29);
			this->rb_short->TabIndex = 3;
			this->rb_short->TabStop = true;
			this->rb_short->Text = L"short";
			this->rb_short->UseVisualStyleBackColor = true;
			this->rb_short->Click += gcnew System::EventHandler(this, &MyForm::rb_short_Click);
			// 
			// btn_close
			// 
			this->btn_close->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn_close->Location = System::Drawing::Point(364, 314);
			this->btn_close->Name = L"btn_close";
			this->btn_close->Size = System::Drawing::Size(135, 40);
			this->btn_close->TabIndex = 3;
			this->btn_close->Text = L"Exit";
			this->btn_close->UseVisualStyleBackColor = true;
			this->btn_close->Click += gcnew System::EventHandler(this, &MyForm::btn_close_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(531, 367);
			this->Controls->Add(this->btn_close);
			this->Controls->Add(this->gb_spp_types);
			this->Controls->Add(this->lbl_rez);
			this->Controls->Add(this->lbl_titlerez);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"lab1. task1";
			this->gb_spp_types->ResumeLayout(false);
			this->gb_spp_types->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btn_close_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void rb_short_Click(System::Object^ sender, System::EventArgs^ e) {
		lbl_rez->Text = Convert::ToString(sizeof(short));
	}
	private: System::Void rb_long_Click(System::Object^ sender, System::EventArgs^ e) {
		lbl_rez->Text = Convert::ToString(sizeof(long));
	}
	private: System::Void rb_char_Click(System::Object^ sender, System::EventArgs^ e) {
		lbl_rez->Text = Convert::ToString(sizeof(char));
	}
	private: System::Void rb_float_Click(System::Object^ sender, System::EventArgs^ e) {
		lbl_rez->Text = Convert::ToString(sizeof(float));
	}
	private: System::Void rb_double_Click(System::Object^ sender, System::EventArgs^ e) {
		lbl_rez->Text = Convert::ToString(sizeof(double));
	}
};
}
