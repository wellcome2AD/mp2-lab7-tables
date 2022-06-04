#pragma once
#include <msclr\marshal_cppstd.h>
#include <fstream>
#include "..\mp2-lab7-tables\TTable.h"
#include "..\mp2-lab7-tables\TSortTable.h"
#include "..\mp2-lab7-tables\TScanTable.h"
#include "..\mp2-lab7-tables\TArrayHash.h"
#include "..\mp2-lab7-tables\TListHash.h"
#include "..\mp2-lab7-tables\TTreeTable.h"
#include "..\mp2-lab7-tables\TBalTree.h"
namespace CppWinForm1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		System::Windows::Forms::Label^ label1;

		System::Windows::Forms::Label^ label2;
		System::Windows::Forms::TextBox^ textBoxRecNumber;
		System::Windows::Forms::TextBox^ textBoxKeyRange;

		System::Windows::Forms::Label^ label3;
		System::Windows::Forms::Label^ label4;
		System::Windows::Forms::Label^ label5;
		System::Windows::Forms::TextBox^ textBoxKey;
		System::Windows::Forms::TextBox^ textBoxResult;
		System::Windows::Forms::Button^ buttonExit;

		System::Windows::Forms::Button^ buttonCreateTable;
		System::Windows::Forms::Button^ buttonFind;
		System::Windows::Forms::Button^ buttonInsert;
		System::Windows::Forms::Button^ buttonDelete;

		System::Windows::Forms::DataGridView^ dataGridView1;
		System::Windows::Forms::DataGridViewTextBoxColumn^ Key;
		System::Windows::Forms::DataGridViewTextBoxColumn^ Value;

		System::Windows::Forms::ComboBox^ comboBox1;

		TTable* table = nullptr;	
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBoxEff;

		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBoxRecNumber = (gcnew System::Windows::Forms::TextBox());
			this->textBoxKeyRange = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBoxKey = (gcnew System::Windows::Forms::TextBox());
			this->textBoxResult = (gcnew System::Windows::Forms::TextBox());
			this->buttonExit = (gcnew System::Windows::Forms::Button());
			this->buttonCreateTable = (gcnew System::Windows::Forms::Button());
			this->buttonFind = (gcnew System::Windows::Forms::Button());
			this->buttonInsert = (gcnew System::Windows::Forms::Button());
			this->buttonDelete = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Key = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Value = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBoxEff = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(304, 34);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(94, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Тип таблицы";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(504, 37);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(107, 17);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Число записей";
			// 
			// textBoxRecNumber
			// 
			this->textBoxRecNumber->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxRecNumber->Location = System::Drawing::Point(617, 34);
			this->textBoxRecNumber->Name = L"textBoxRecNumber";
			this->textBoxRecNumber->Size = System::Drawing::Size(56, 21);
			this->textBoxRecNumber->TabIndex = 8;
			// 
			// textBoxKeyRange
			// 
			this->textBoxKeyRange->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxKeyRange->Location = System::Drawing::Point(617, 65);
			this->textBoxKeyRange->Name = L"textBoxKeyRange";
			this->textBoxKeyRange->Size = System::Drawing::Size(56, 21);
			this->textBoxKeyRange->TabIndex = 9;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(484, 66);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(127, 17);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Диапазон ключей";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(568, 113);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(43, 17);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Ключ";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(535, 148);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(76, 17);
			this->label5->TabIndex = 12;
			this->label5->Text = L"Результат";
			// 
			// textBoxKey
			// 
			this->textBoxKey->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxKey->Location = System::Drawing::Point(617, 113);
			this->textBoxKey->Name = L"textBoxKey";
			this->textBoxKey->Size = System::Drawing::Size(56, 21);
			this->textBoxKey->TabIndex = 13;
			// 
			// textBoxResult
			// 
			this->textBoxResult->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxResult->Location = System::Drawing::Point(617, 147);
			this->textBoxResult->Name = L"textBoxResult";
			this->textBoxResult->ReadOnly = true;
			this->textBoxResult->Size = System::Drawing::Size(56, 21);
			this->textBoxResult->TabIndex = 14;
			// 
			// buttonExit
			// 
			this->buttonExit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonExit->Location = System::Drawing::Point(347, 384);
			this->buttonExit->Name = L"buttonExit";
			this->buttonExit->Size = System::Drawing::Size(167, 31);
			this->buttonExit->TabIndex = 15;
			this->buttonExit->Text = L"Выход";
			this->buttonExit->UseVisualStyleBackColor = true;
			this->buttonExit->Click += gcnew System::EventHandler(this, &MyForm::buttonExit_Click);
			// 
			// buttonCreateTable
			// 
			this->buttonCreateTable->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonCreateTable->Location = System::Drawing::Point(307, 200);
			this->buttonCreateTable->Name = L"buttonCreateTable";
			this->buttonCreateTable->Size = System::Drawing::Size(257, 27);
			this->buttonCreateTable->TabIndex = 16;
			this->buttonCreateTable->Text = L"Создать таблицу";
			this->buttonCreateTable->UseVisualStyleBackColor = true;
			this->buttonCreateTable->Click += gcnew System::EventHandler(this, &MyForm::buttonCreateTable_Click);
			// 
			// buttonFind
			// 
			this->buttonFind->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonFind->Location = System::Drawing::Point(307, 243);
			this->buttonFind->Name = L"buttonFind";
			this->buttonFind->Size = System::Drawing::Size(257, 27);
			this->buttonFind->TabIndex = 17;
			this->buttonFind->Text = L"Поиск по ключу";
			this->buttonFind->UseVisualStyleBackColor = true;
			this->buttonFind->Click += gcnew System::EventHandler(this, &MyForm::buttonFind_Click);
			// 
			// buttonInsert
			// 
			this->buttonInsert->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonInsert->Location = System::Drawing::Point(307, 286);
			this->buttonInsert->Name = L"buttonInsert";
			this->buttonInsert->Size = System::Drawing::Size(257, 27);
			this->buttonInsert->TabIndex = 18;
			this->buttonInsert->Text = L"Добавить запись";
			this->buttonInsert->UseVisualStyleBackColor = true;
			this->buttonInsert->Click += gcnew System::EventHandler(this, &MyForm::buttonInsert_Click);
			// 
			// buttonDelete
			// 
			this->buttonDelete->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonDelete->Location = System::Drawing::Point(307, 331);
			this->buttonDelete->Name = L"buttonDelete";
			this->buttonDelete->Size = System::Drawing::Size(257, 27);
			this->buttonDelete->TabIndex = 19;
			this->buttonDelete->Text = L"Удалить запись";
			this->buttonDelete->UseVisualStyleBackColor = true;
			this->buttonDelete->Click += gcnew System::EventHandler(this, &MyForm::buttonDelete_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) { this->Key, this->Value });
			this->dataGridView1->Location = System::Drawing::Point(11, 12);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->dataGridView1->Size = System::Drawing::Size(256, 363);
			this->dataGridView1->TabIndex = 20;
			// 
			// Key
			// 
			this->Key->HeaderText = L"Key";
			this->Key->Name = L"Key";
			this->Key->ReadOnly = true;
			// 
			// Value
			// 
			this->Value->HeaderText = L"Value";
			this->Value->Name = L"Value";
			this->Value->ReadOnly = true;
			// 
			// comboBox1
			// 
			this->comboBox1->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(6) {
				L"Неупорядоченная", L"Упорядоченная",
					L"Хэш-таблица (массив)", L"Хэш-таблица (список)", L"Дерево", L"АВЛ-дерево"
			});
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				L"Неупорядоченная", L"Упорядоченная", L"Хэш-таблица (массив)",
					L"Хэш-таблица (список)", L"Дерево", L"АВЛ-дерево"
			});
			this->comboBox1->Location = System::Drawing::Point(273, 60);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(166, 23);
			this->comboBox1->TabIndex = 22;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(85, 378);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(117, 17);
			this->label6->TabIndex = 23;
			this->label6->Text = L"Эффективность:";
			// 
			// textBoxEff
			// 
			this->textBoxEff->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxEff->Location = System::Drawing::Point(112, 398);
			this->textBoxEff->Name = L"textBoxEff";
			this->textBoxEff->ReadOnly = true;
			this->textBoxEff->Size = System::Drawing::Size(56, 21);
			this->textBoxEff->TabIndex = 24;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(704, 427);
			this->Controls->Add(this->textBoxEff);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->buttonDelete);
			this->Controls->Add(this->buttonInsert);
			this->Controls->Add(this->buttonFind);
			this->Controls->Add(this->buttonCreateTable);
			this->Controls->Add(this->buttonExit);
			this->Controls->Add(this->textBoxResult);
			this->Controls->Add(this->textBoxKey);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBoxKeyRange);
			this->Controls->Add(this->textBoxRecNumber);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->MaximumSize = System::Drawing::Size(720, 466);
			this->MinimumSize = System::Drawing::Size(720, 466);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"mp2-lab7 Tables";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private:
	int table_index = 0;
	void FillDataGridView()
	{
		int index;
		TRecord record;

		dataGridView1->Rows->Clear();
		for (table->Reset(); !table->IsEnd(); table->GoNext())
		{
			record = table->GetCurrentRecord();
			String^ key = record.key.ToString();
			String^ value = msclr::interop::marshal_as<System::String^>(record.value);
			dataGridView1->Rows->Add(key, value);
		}
		dataGridView1->Refresh();

		if (table_index == 5)
		{
			std::ofstream file("balanced_tree.txt", std::ios::trunc);
			file << *table;
			file.close();
			system("start notepad balanced_tree.txt");
		}
		else if (table_index == 4)
		{
			std::ofstream file("tree.txt", std::ios::trunc);
			file << *table;
			file.close();
			system("start notepad tree.txt");
		}
	}
	void SelectRowContainingKey(TKey key)
	{
		for (int i = 0; i < dataGridView1->Rows->Count; i++)
		{
			String^ key_value = dataGridView1->Rows[i]->Cells["Key"]->Value->ToString()->Trim();
			if (key_value == key.ToString())
			{
				dataGridView1->Rows[i]->Selected = true;
				dataGridView1->CurrentCell = dataGridView1->Rows[i]->Cells[0];
			}
		}
	}
	System::Void buttonCreateTable_Click(System::Object^ sender, System::EventArgs^ e) 
	{		
		int recNum;
		try
		{
			recNum = int::Parse(textBoxRecNumber->Text);
		}
		catch (...)
		{
			MessageBox::Show("Ошибка ввода количества записей");
			return;
		}
		try
		{
			int recNum = int::Parse(textBoxRecNumber->Text);
		}
		catch (...)
		{
			MessageBox::Show("Ошибка ввода количества записей");
			return;
		}
		
		table_index = comboBox1->SelectedIndex;
		switch (table_index)
		{
		case 0:
			table = new TScanTable(recNum);
			break;
		case 1:
			table = new TSortTable(recNum);
			break;
		case 2:
			table = new TArrayHash(recNum);
			break;
		case 3:
			table = new TListHash(recNum);
			break;
		case 4:
			table = new TTreeTable();
			break;
		case 5:
			table = new TBalTree();
			break;
		default:
			MessageBox::Show("Выберите тип таблицы");
			return;
		}

		int keyRange;
		try
		{
			keyRange = int::Parse(textBoxKeyRange->Text);
		}
		catch (...)
		{
			MessageBox::Show("Ошибка ввода диапазона ключей");
			return;
		}

		if (keyRange <= recNum)
		{
			MessageBox::Show("Слишком маленький диапазон ключей для такого количества записей");
			return;
		}

		srand(time(NULL));
		TRecord record;
		for (int i = 0; i < recNum; ++i)
		{
			bool is_inserted = false;
			while (is_inserted != true)
			{
				record.key = rand() % keyRange;
				record.value = std::string("record#") + std::to_string(i);
				is_inserted = table->Insert(record);
			}
		}

		FillDataGridView();
	}		
	System::Void buttonExit_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		Application::Exit();
	}
	System::Void buttonFind_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if (table == nullptr)
		{
			MessageBox::Show("Вы не создали таблицу. Нажмите \"Создать\"");
			return;
		}
		TKey key;
		try
		{
			key = int::Parse(textBoxKey->Text);
		}
		catch (...)
		{
			MessageBox::Show("Ошибка ввода ключа");
			return;
		}
		table->ClearEffectiveness();
		bool result = table->Find(key);
		if (result)
		{
			SelectRowContainingKey(key);
		}
		textBoxResult->Text = result.ToString();
		textBoxEff->Text = table->GetEffectiveness().ToString();
	}
	System::Void buttonInsert_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if (table == nullptr)
		{
			MessageBox::Show("Вы не создали таблицу. Нажмите \"Создать\"");
			return;
		}
		if (table->IsFull())
		{
			MessageBox::Show("Таблица полна. Нажмите \"Удалить запись\"");
			return;
		}
		TKey key;
		try
		{
			key = int::Parse(textBoxKey->Text);
		}
		catch (...)
		{
			MessageBox::Show("Ошибка ввода ключа");
			return;
		}
		TRecord rec = { key, std::string("record#") + std::to_string(key) };
		table->ClearEffectiveness();
		bool result = table->Insert(rec);

		FillDataGridView();
		SelectRowContainingKey(key);

		textBoxResult->Text = result.ToString();
		textBoxEff->Text = table->GetEffectiveness().ToString();
	}
	System::Void buttonDelete_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if (table == nullptr)
		{
			MessageBox::Show("Вы не создали таблицу. Нажмите \"Создать\"");
			return;
		}
		if (table->IsEmpty())
		{
			MessageBox::Show("Таблица пуста. Нажмите \"Добавить запись\"");
			return;
		}
		TKey key;
		try
		{
			key = int::Parse(textBoxKey->Text);
		}
		catch (...)
		{
			MessageBox::Show("Ошибка ввода ключа");
			return;
		}
		table->ClearEffectiveness();
		bool result = table->Delete(key);

		FillDataGridView();

		textBoxResult->Text = result.ToString();
		textBoxEff->Text = table->GetEffectiveness().ToString();
	}
};
}
