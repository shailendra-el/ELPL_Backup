/*
 * Copyright 2019 Simon Persson <simon.persson@mykolab.com>
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License or (at your option) version 3 or any later version
 * accepted by the membership of KDE e.V. (or its successor approved
 * by the membership of KDE e.V.), which shall act as a proxy 
 * defined in Section 14 of version 3 of the license.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef FILEDIGGER_H
#define FILEDIGGER_H

#include <KMainWindow>
#include <QUrl>

class KDirOperator;
class MergedVfsModel;
class MergedRepository;
class VersionListModel;
class QListView;
class QModelIndex;
class QTreeView;

class FileDigger : public KMainWindow
{
	Q_OBJECT
public:
	explicit FileDigger(QString pRepoPath, QString pBranchName, QWidget *pParent = nullptr);
	QSize sizeHint() const override;

protected slots:
	void updateVersionModel(const QModelIndex &pCurrent, const QModelIndex &pPrevious);
	void open(const QModelIndex &pIndex);
	void restore(const QModelIndex &pIndex);
	void repoPathAvailable();
	void checkFileWidgetPath();
	void enterUrl(const QUrl &pUrl);

protected:
	MergedRepository *createRepo();
	void createRepoView(MergedRepository *pRepository);
	void createSelectionView();
	MergedVfsModel *mMergedVfsModel{};
	QTreeView *mMergedVfsView{};

	VersionListModel *mVersionModel{};
	QListView *mVersionView{};
	QString mRepoPath;
	QString mBranchName;
	KDirOperator *mDirOperator;
};

#endif // FILEDIGGER_H
