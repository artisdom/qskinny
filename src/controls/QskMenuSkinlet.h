#pragma once

#include <QskPopupSkinlet.h>
#include <memory>

class QskMenu;

class QSK_EXPORT QskMenuSkinlet : public QskPopupSkinlet
{
    Q_GADGET

    using Inherited = QskPopupSkinlet;

  public:
    enum NodeRole
    {
        PanelRole = QskPopupSkinlet::RoleCount,
        RoleCount
    };

    Q_INVOKABLE QskMenuSkinlet( QskSkin* = nullptr );
    ~QskMenuSkinlet() = default;

    QRectF subControlRect( const QskSkinnable*,
        const QRectF&, QskAspect::Subcontrol ) const override;

    int sampleCount( const QskSkinnable*, QskAspect::Subcontrol ) const override;

    QRectF sampleRect( const QskSkinnable*,
        const QRectF&, QskAspect::Subcontrol, int index ) const override;

    int sampleIndexAt( const QskSkinnable*,
        const QRectF&, QskAspect::Subcontrol, const QPointF& ) const override;

    QskAspect::States sampleStates( const QskSkinnable*,
        QskAspect::Subcontrol, int index ) const override;

    QVariant sampleAt( const QskSkinnable*,
        QskAspect::Subcontrol, int index ) const override;

    QSizeF sizeHint( const QskSkinnable*,
        Qt::SizeHint, const QSizeF& ) const override;

  protected:
    QSGNode* updateContentsNode( const QskPopup*, QSGNode* ) const override;
    QSGNode* updateMenuNode( const QskSkinnable*, QSGNode* ) const;

    QSGNode* updateSampleNode( const QskSkinnable*,
        QskAspect::Subcontrol, int index, QSGNode* ) const override;

  private:
    class PrivateData;
    std::unique_ptr< PrivateData > m_data;
};